# Author : Pierre Schnizer 
"""
Wrapper over the functions as described in Chaper 6 of the
reference manual.

There are routines for finding real  and complex roots of quadratic and cubic
equations  using analytic  methods. An  iterative polynomial  solver  is also
available for finding the roots of general polynomials with real coefficients
(of any order).

All the doc strings were taken form the gsl reference document.
"""
import pygsl
import pygsl._numobj as Numeric
import _poly

get_typecode = pygsl.get_typecode

GSL_SUCCESS = pygsl.errno.GSL_SUCCESS
GSL_FAILURE = pygsl.errno.GSL_FAILURE


def poly_eval(*args):
    """
    This function evaluates the polynomial
    c[0] + c[1] x + c[2] x^2 + \dots + c[len-1] x^{len-1}
    using Horner's method for stability

    input: c, x
        c ... array of coefficients
        x ... 
        
    output: y    
    """
    return _poly.gsl_poly_eval(*args)

class poly_dd:
    """
    This class manipulates polynomials stored in Newton's divided-difference
    representation. The use of divided-differences is described in
    Abramowitz & Stegun sections 25.1.4, 25.2.26. 
    """
    def __init__(self, xa, ya):
        """
        
        This method computes a divided-difference representation of the
        interpolating polynomial for the points (xa, ya) stored in the arrays
        xa and ya. The divided-differences of (xa,ya) are stored internally.

        input : xa, ya
            xa ... array of x values
            ya ... array of y values

            These arrays must have the same size.
        """
        self.xa = xa
        tmp, dd = _poly.gsl_poly_dd_init(xa, ya)
        assert(tmp == 0)
        self.dd = dd
        
    def eval(self, x):
        """
        This method evaluates the polynomial stored in divided-difference form
        at point x.

        input : x
           x ... point

        output : y   
        """        
        return _poly.gsl_poly_dd_eval(self.dd, self.xa, x)

    def taylor(self, xp):
        """
        This method converts the internal divided-difference representation of a
        polynomial to a Taylor expansion.

        input : xp
             xp ... point to expand about
        """
        w = Numeric.zeros(self.dd.shape, get_typecode(self.dd))
        return _poly.gsl_poly_dd_taylor(xp, self.dd, self.xa, w)
    
class poly_complex:
    """

    The roots of polynomial equations cannot be found analytically beyond the
    special cases  of the quadratic,  cubic and quartic equation.  This class
    uses an  iterative method to find  the approximate locations  of roots of
    higher order polynomials.


    """
    def __init__(self, dimension):
        """
        Initalizes the class.

        Input : n
            n ... number of coefficients of the polynomial.
        """
        self._myptr = None
        self._myptr =  _poly.gsl_poly_complex_workspace_alloc(dimension)

    def solve(self, a):
        """        
        This function computes the roots of the general polynomial P(x) = a_0
        + a_1 x + a_2 x^2 + ... + a_{n-1} x^{n-1} using balanced-QR reduction
        of the companion matrix. The  parameter n specifies the length of the
        coefficient array. The coefficient of  the highest order term must be
        non-zero.  The function  requires a  workspace w  of  the appropriate
        size. The  n-1 roots are  returned in the  packed complex array  z of
        length 2(n-1), alternating real and imaginary parts.

        The  function returns  GSL_SUCCESS if  all  the roots  are found  and
        GSL_EFAILED if the QR reduction does not converge.

        input : z
           z ... Array of complex coefficients.
           
        output : flag, z_out
           flag ... GSL_SUCCESS or GSL_FAILURE 
           z    ... Array of complex roots
        """
        return _poly.gsl_poly_complex_solve(a, self._myptr)
    
    def __del__(self):
        if hasattr(self, '_myptr'):
            if self._myptr != None:
                _poly.gsl_poly_complex_workspace_free(self._myptr)    


    
def solve_quadratic(*args):
    """
    a x^2 + b x + c = 0

    The number  of real  roots (either  zero or two)  is returned,  and their
    locations are stored in x0 and x1. If no real roots are found then x0 and
    x1 are not modified. When two real  roots are found they are stored in x0
    and x1 in ascending order. The case of coincident roots is not considered
    special. For example (x-1)^2=0 will  have two roots, which happen to have
    exactly equal values.

    The number of roots found depends on the sign of the discriminant b^2 - 4
    a  c. This  will  be subject  to  rounding and  cancellation errors  when
    computed in double  precision, and will also be subject  to errors if the
    coefficients  of the  polynomial are  inexact. These  errors may  cause a
    discrete change  in the  number of roots.  However, for  polynomials with
    small  integer  coefficients  the  discriminant can  always  be  computed
    exactly.

    input : a, b, c

    output : n, r1, r2
        n  ... number of roots found
        r1 ... first root
        r2 ... second root
    """
    return apply(_poly.gsl_poly_solve_quadratic, args)

def complex_solve_quadratic(*args):
    """
    The complex version of solve quadratic. See solve_quadratic for explanation.
    """
    return apply(_poly.gsl_poly_complex_solve_quadratic, args)

def solve_cubic(*args):
    """
    This function finds the real  roots of the cubic equation,

    x^3 + a x^2 + b x + c = 0

    with a leading coefficient of unity. The number of real roots (either one
    or  three) is  returned, and  their locations  are stored  in x0,  x1 and
    x2. If one real  root is found then only x0 is  modified. When three real
    roots are found they are stored in  x0, x1 and x2 in ascending order. The
    case  of coincident  roots is  not considered  special. For  example, the
    equation (x-1)^3=0 will have three roots with exactly equal values.

    input : a, b, c

    output : n, r1, r2
        n  ... number of roots found
        r1 ... first root
        r2 ... second root
        r3 ... third root

    """
    return apply(_poly.gsl_poly_solve_cubic, args)

def complex_solve_cubic(*args):
    """

    This function finds the complex roots of the cubic equation,

    z^3 + a z^2 + b z + c = 0
    
    The number of complex roots  is returned (always three) and the locations
    of the  roots are  stored in  z0, z1 and  z2. The  roots are  returned in
    ascending order, sorted first by  their real components and then by their
    imaginary components.

    input : a, b, c

    output : n, r1, r2
        n  ... number of roots found
        r1 ... first root
        r2 ... second root
        r3 ... third root

    """
    return apply(_poly.gsl_poly_complex_solve_cubic, args)


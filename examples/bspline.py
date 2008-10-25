from pygsl import bspline, multifit, rng
import pygsl._numobj as numx

N = 200
ncoeffs = 8
nbreak = ncoeffs - 2
bspline = bspline.bspline
def run():
    r = rng.rng()
    bw = bspline(4, nbreak)


    # Data to be fitted
    x = 15. / (N-1) * numx.arange(N)
    y = numx.cos(x) * numx.exp(0.1 * x)    
    sigma = .1
    w = 1.0 / sigma**2 * numx.ones(N) 
    dy = r.gaussian(sigma, N)
    y  = y + dy

    # use uniform breakpoints on [0, 15] 
    bw.knots_uniform(0.0, 15.0)

    X = numx.zeros((N, ncoeffs))
    for i in range(N):
        B = bw.eval(x[i])
        X[i,:] = B
        
    # do the fit
    c, cov, chisq = multifit.wlinear(X, w, y, multifit.linear_workspace(N, ncoeffs))

    # output the smoothed curve
    res_y = []
    res_y_err = []
    for i in range(N):
        B = bw.eval(x[i])
        yi, yi_err = multifit.linear_est(B, c, cov)
        res_y.append(yi)
        res_y_err.append(yi_err)
        #print yi, yerr
    res_y = numx.array(res_y)
    res_y_err = numx.array(res_y_err)    
    return (x, y,), (x, res_y),  res_y_err
    
        
if __name__ == '__main__':
    run()


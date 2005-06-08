"""
The wrapper for the wavelets are in the catchall for all the transfroms.

They are gathered here to be 

"""
from pygsl._transform import daubechies, haar, bspline
from pygsl._transform import daubechies_centered, haar_centered, bspline_centered
from pygsl._transform import wavelet_workspace
workspace = wavelet_workspace

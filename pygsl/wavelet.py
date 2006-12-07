"""
Wavelet transfroms as provided by GSL
"""
from pygsl._transform import daubechies, haar, bspline
from pygsl._transform import daubechies_centered, haar_centered, bspline_centered
from pygsl._transform import wavelet_workspace
workspace = wavelet_workspace

import pygsl._histogram

class histogram:
    """
    """

    def __init__(self,n):
        """
        """
        self._histogram=pygsl._histogram.alloc(n)

    def __del__(self):
        """
        """
        if self._histogram is not None:
            pygsl._histogram.free(self._histogram)
            self._histogram=None

    def reset(self):
        """
        """
        if self._histogram is not None:
            pygsl._histogram.reset(self._histogram)

    def set_ranges_uniform(self,xmin,xmax):
        """
        """
        if self._histogram is not None:
            pygsl._histogram.set_ranges_uniform(self._histogram,xmin,xmax)

    def increment(self,x):
        """
        """
        if self._histogram is not None:
            pygsl._histogram.increment(self._histogram,x)

    def accumulate(self,x,weight):
        """
        """
        if self._histogram is not None:
            pygsl._histogram.accumulate(self._histogram,x,weight)

    def min(self):
        """
        """
        if self._histogram is not None:
            return pygsl._histogram.min(self._histogram)

    def max(self):
        """
        """
        if self._histogram is not None:
            return pygsl._histogram.max(self._histogram)

    def bins(self):
        """
        """
        if self._histogram is not None:
            return pygsl._histogram.bins(self._histogram)


    def get(self,n):
        """
        """
        if self._histogram is not None:
            return pygsl._histogram.get(self._histogram,n)

    def get_range(self,n):
        """
        """
        if self._histogram is not None:
            return pygsl._histogram.get_range(self._histogram,n)

    def find(self,value):
        """
        """
        if self._histogram is not None:
            return pygsl._histogram.find(self._histogram,value)

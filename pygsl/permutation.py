# Author : Fabian Jakobs
import gslwrap

class Permutation(gslwrap.Permutation):
    def tolist(self):
        l = []
        for i in range(len(self)):
            l.append(self[i])
        return l

    def __str__(self):
        return self.tolist().__str__()

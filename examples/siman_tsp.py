#!/usr/bin/env python
"""

A dirty implementation of the travelling sales man problem as given in the
file siman/siman_tsp.c.

Original Copyright:
/* siman/siman_tsp.c
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Mark Galassi
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

"""

import copy
import sys
import time
import pygsl.siman as siman
import pygsl.rng   as rng
from pygsl import _numobj as numx

sin = numx.sin
cos = numx.cos
pi  = numx.pi

class City:
    def __init__(self, name, lat, longitude):
        self._name = name
        self._lat = lat
        self._longitude = longitude
        self._number = None

    def __str__(self):
        t = (self._name, self._lat, self._longitude, self._number)
        return "City % 15s @ (% 8.2f, % 8.2f) Number %2d" % t
        
    def GetData(self):
        return self._lat, self._longitude

    def GetName(self):
        return Name

    def SetNumber(self, number):
        self._number = int(number)

    def GetNumber(self):
        assert(self._number != None)
        return self._number

    
        
# in this table, latitude and longitude are obtained from the US
#   Census Bureau, at http://www.census.gov/cgi-bin/gazetteer */
cities =(City("Santa Fe",       -105.95, 35.68,),
         City("Phoenix",        -112.07, 33.54,),
         City("Albuquerque",    -106.62, 35.12,),
         City("Clovis",         -103.20, 34.41,),
         City("Durango",        -107.87, 37.29,),
         City("Dallas",          -96.77, 32.79,),
         City("Tesuque",        -105.92, 35.77,),
         City("Grants",         -107.84, 35.15,),
         City("Los Alamos",     -106.28, 35.89,),
         City("Las Cruces",     -106.76, 32.34,),
         City("Cortez",         -108.58, 37.35,),
         City("Gallup",         -108.74, 35.52,))

n_cities = len(cities)
distance_matrix = numx.zeros((n_cities, n_cities))

cities_vec = numx.array(map(lambda x: x.GetData(), cities))
for i in range(len(cities)):
    cities[i].SetNumber(i)
    
earth_radius = 6375.000
#n_cities = 6

# distance between two cities
def city_distance(c):
    la = c[:,0]
    lo = c[:,1]
    sla = sin(la*pi/180)
    cla = cos(la*pi/180)
    slo = sin(lo*pi/180)
    clo = sin(lo*pi/180)

    x = cla * clo
    y = cla * slo
    z = sla

    d = numx.product(x) * numx.product(y) * numx.product(z)    
    return numx.arccos(d) * earth_radius

class Tsp:
    """
    Travelling sales person

    Class describing the problem
    """
    def __init__(self):
        # Just a sequence of numbers describing the route.        
        self._route = None
        
        # Just to list the additional required objects
        #self.n_cities
        #self.r_cities

    def GetRoute(self):        
        return self._route

    def SetRoute(self, route):
        self._route = route

    def SetNCities(self, n_cities):
        self.n_cities = n_cities
        self.r_cities = numx.arange(n_cities)
        
    def EFunc(self):
        E = 0
        route = self._route
        for i in self.r_cities:
            E += distance_matrix[route[i]][route[(i + 1) % self.n_cities]]
        return E

    def Metric(self, other):
        route1 = self._route
        route2 = other.GetRoute()
        distance = 0
        for i in self.r_cities:
            if route1[i] == route2[i]:
                countinue              
            distance += 1
        return distance

    def Step(self, rng, step_size):
        x1 = rng.get() % (self.n_cities-1) + 1
        while 1:
            x2 = rng.get() % (self.n_cities-1) + 1
            if x1 != x2:
                break
        x1 = int(x1)
        x2 = int(x2)
        self._route[x1], self._route[x2] = self._route[x2], self._route[x1]

    def Print(self):
        for i in self.r_cities:
            print " %d " % self._route[i],
           
    def Clone(self):
        clone = copy.copy(self)
        clone.SetRoute(copy.copy(self._route))
        return clone
    
def prepare_distance_matrix():
    for i in range(n_cities):
        for j in range(n_cities):
            if i == j:
                dist = 0
            else:
                cities = numx.take(cities_vec, (i,j), 0)
                dist = city_distance(cities)
            distance_matrix[i][j] = dist

def print_distance_matrix():
    for i in range(n_cities):
        for j in range(n_cities):
            print "% 8.2f" % distance_matrix[i][j],
        print     

def siman_exp():
    prepare_distance_matrix()

    # set up a trivial initial route */
    print("# initial order of cities:\n")
    for city in cities:
        print city


    #print " # distance matrix is:"
    #print_distance_matrix();

    mytsp = Tsp()
    mytsp.SetRoute(numx.arange(n_cities))
    mytsp.SetNCities(n_cities)
    result = siman.solve(rng.rng(), mytsp)
    route  = result.GetRoute()
    print("# final order of cities:\n")
    for i in route:
        print cities[i]




class ExhaustiveSearch:
    """
     James Theiler's recursive algorithm for generating all routes

      [only works for 12] search the entire space for solutions
    """
    def __init__(self):
        self.best_E   = 1.0e100
        self.second_E = 1.0e100
        self.third_E  = 1.0e100
        self.best_route   = numx.arange(n_cities)
        self.second_route = numx.arange(n_cities)
        self.third_route  = numx.arange(n_cities)
        self.tsp = Tsp()
        self.tsp.SetNCities(n_cities)
        self.r_cities = numx.arange(n_cities)
        self.__runs = 0
        self.__total_runs = 68588312
        self.__time_stamp = 0
        
    def arange_routes(self, route):
        """
        """
        #rint "Calculating Energy ...",
        E = 0
        i_ind = numx.take(route, self.r_cities)
        j_ind = numx.take(route, (self.r_cities + 1) % n_cities)
        for i in self.r_cities:
            E += distance_matrix[route[i]][route[(i + 1) % n_cities]]
        #print self.E
        if E < self.best_E:
            self.third_E = self.second_E
            self.third_route[:] = self.second_route[:]
            self.second_E = self.best_E
            self.second_route[:] = self.best_route[:]
            self.best_E = E
            self.best_route[:] = route[:]
        elif E < self.second_E:
            self.third_E = self.second_E
            self.third_route[:] = self.second_route[:]
            self.second_E = E
            self.second_route[:] = route[:]
        elif E < self.third_E:
            self.third_E = E;
            route[:] = self.third_route[:]
        else:
            # Nothing to do
            pass

    def forcastendtime(self):
        """
        """
        now = time.time()
        dt = now -  self.__time_stamp
        required_time = (self.__total_runs - self.__runs) * dt / self.__runs
        if required_time > 0:
            end = now + required_time
        else:
            # well self.__total_runs is not a good guess any more
            end = now
        tmp = time.strftime("%Y %m %d %H:%M:%S", time.localtime(end))
        sys.stdout.write("\r" + " " * 78 + "\r"),
        sys.stdout.write("end %s " % tmp)
        sys.stdout.flush()
        
    def do_all_perms(self, route, n):
        self.__runs += 1
        if self.__runs % (1000 * 1000) == 0 :
            self.forcastendtime()
            
        elif self.__runs % (1000 * 20) == 0 :
            sys.stdout.write("."),
            sys.stdout.flush()
            
        if n == (n_cities - 1):
            self.arange_routes(route)
            #print "finished"
            return
            pass
        elif n > n_cities - 1 :
            raise ValueError
        else:
            #print "range",
            new_route = copy.copy(route)
            for j in range(n, n_cities):
                new_route[j], new_route[n] =  new_route[n], new_route[j]
                #print "j,", j
                self.do_all_perms(new_route, n+1)

    def search(self):
        initial_route = numx.arange(n_cities)
        self.__time_stamp = int(time.time())
        sys.stdout.write(" " * 79 + "\n")
        self.do_all_perms(initial_route, 1)

        print " " * 78
        print "\n"
        print "Initial route: "
        for i in initial_route:
            print cities[i]

        print "Required %d runs estimated %d runs" % (self.__runs, self.__total_runs)
        print 
        print "Best route: "
        for i in self.best_route:
            print cities[i]

        print 
        print "Second route: "
        for i in self.second_route:
            print cities[i]

        print 
        print "Third route: "
        for i in self.third_route:
            print cities[i]


def exhaustive_search():
    prepare_distance_matrix()
    ExhaustiveSearch().search()

if __name__ == "__main__":
    siman_exp()
    #exhaustive_search()

#!/usr/bin/env python

import Tkinter
import tkSimpleDialog
import tkFileDialog
import pygsl.histogram

class histogram_canvas(Tkinter.Canvas):
    """
    displays a histogram in a canvas, tracks changes to the histogram
    """

    # holds the histogram
    my_histogram=None
    # is the point where everything starts
    basepoint=(10,200)
    # how to get to the next histogram bar
    next_offset=(10,0)
    # the bar rectangle geometry is bar_fix+bar_scale*value
    bar_fix = (10,-1)
    bar_scale = (0,-1)

    #list for bar item lookups
    bar_items = None

    def __init__(self,histogram=None,master=None,**kw):
        """
        initialisation routine: initialises canvas and creates histogram items
        """
        Tkinter.Canvas.__init__(self,master=master,cnf=kw)
        if histogram is not None:
            self.new_histogram(histogram)

    def delete_histogram(self):
        """
        deletes containing histogram and clears canvas
        """
        self.my_histogram=None
        #if necessary purge bar items
        if self.bar_items is not None:
            map(self.delete,self.bar_items)
        self.bar_items=None

    def new_histogram(self, histogram):
        """
        adds histogram
        """
        if self.my_histogram is not None:
            self.delete_histogram()
        self.my_histogram=histogram
        self.create_histogram_items()

    def create_histogram_items(self):
        """
        creates necessary histogram items
        """
        #if necessary purge bar items
        if self.bar_items is not None:
            map(self.delete,self.bar_items)
        self.bar_items=[]

        for i in xrange(0,self.my_histogram.bins()):
            self.bar_items.append(self.create_rectangle(self.get_bar_coordinates(i),tags=str(i)))

    def update_histogram_items(self):
        """
        simple update
        """
        if len(self.bar_items)!=len(self.my_histogram):
            raise AssertionError,"expect to have same bin number"

        for i in xrange(0,self.my_histogram.bins()):
            self.coords(self.bar_items[i],self.get_bar_coordinates(i))

    def get_bar_coordinates(self,i):
        """
        central method to determine bar coordinates
        """
        x0=self.basepoint[0]+self.next_offset[0]*i
        x1=x0+self.bar_fix[0]+self.bar_scale[0]*self.my_histogram[i]
        y0=self.basepoint[1]+self.next_offset[1]*i
        y1=y0+self.bar_fix[1]+self.bar_scale[1]*self.my_histogram[i]
        return (x0,y0,x1,y1)

class example_application(Tkinter.Frame):
    """
    holds the code for the aplication
    """
    def __init__(self,master=None):
        """
        runs the example application
        """
        Tkinter.Frame.__init__(self,master=master)
        self.winfo_toplevel().title("histogram example")
        self.hist=pygsl.histogram.histogram(10)
        self.hist.set_ranges_uniform(0,10)
        self.hist[0]=20
        self.hist[4]=100
        self.hist[9]=50
        self.create_widgets()
        self.pack(fill=Tkinter.BOTH, expand=1)
        self.mainloop()

    def create_widgets(self):
        """
        a menu, the histogram canvas, some buttons
        """
        # histogram
        self.hist_canvas=histogram_canvas(histogram=self.hist,master=self,bg="white")
        self.hist_canvas.pack(fill=Tkinter.BOTH, expand=1,side=Tkinter.TOP)

        # button bar
        button_frame=Tkinter.Frame(self)
        load_button=Tkinter.Button(button_frame, text="Load", command=self.load_action)
        load_button.pack(side=Tkinter.LEFT, padx=5, pady=5)
        load_button=Tkinter.Button(button_frame, text="Save", command=self.save_action)
        load_button.pack(side=Tkinter.LEFT, padx=5, pady=5)
        new_button=Tkinter.Button(button_frame, text="New", command=self.new_action)
        new_button.pack(side=Tkinter.LEFT, padx=5, pady=5)
        quit_button=Tkinter.Button(button_frame, text="Quit", command=self.quit_action)
        quit_button.pack(side=Tkinter.RIGHT, padx=5, pady=5)
        button_frame.pack(expand=1,fill=Tkinter.X)

    def new_action(self):
        """
        """
        self.ask_for_save_and_delete()
        # ask for parameters of new histogram
        self.hist=pygsl.histogram.histogram(20)
        self.hist_canvas.new_histogram(self.hist)

    def load_action(self):
        """
        """
        self.ask_for_save_and_delete()
        # file dialog
        file_name=tkFileDialog.askopenfilename()
        if not file_name:
            return
        try:
            hist_file=file(file_name,"r")
            first_line=hist_file.readline().rstrip()
        except IOError:
            print "sorry, can not load to %s"%file_name
            return
        if first_line[:10]!="histogram(":
            print "not of required file type"
            return
        bins=int(first_line[10:-1])
        try:
            self.hist=pygsl.histogram.histogram(bins)
            self.hist.scanf(hist_file)
        except pygsl.error.gsl_Error:
            print "sorry, gsl can not load to %s"%file_name
        hist_file.close()
        self.hist_canvas.new_histogram(self.hist)

    def save_action(self):
        """
        """
        if self.hist is None:
            return
        file_name=tkFileDialog.asksaveasfilename()
        if not file_name:
            return
        try:
            hist_file=file(file_name,"w")
            hist_file.write("histogram(%d)\n"%self.hist.bins())
            hist_file.flush()
            self.hist.printf(hist_file)
        except IOError:
            print "sorry, can not save to %s"%file_name
        except pygsl.error.gsl_Error:
            print "sorry, gsl can not save to %s"%file_name
        hist_file.close()


    def ask_for_save_and_delete(self):
        """
        ask if user likes to save data before deleting them,
        delete them after that
        """
        if self.hist is not None:
            # ToDo: ask if save before loading a new one
            self.hist=None
            self.hist_canvas.delete_histogram()

    def quit_action(self):
        self.quit()

if __name__ == "__main__":
    example_application()

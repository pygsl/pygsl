# Makefile for pygsl manual
#
# Copyright (C) 2002,2003 Jochen Küpper


# some programs, might need adjustment
GZIP		= gzip -9f
MKHOWTO		= python2 ./mkhowto --a4 


# some information for generated html
MAILINGLIST	= pygsl@lists.sourceforge.net
ADDRESS		= "Send comments to the <a href=\"mailto:$(MAILINGLIST)\">PyGSL community</a>."
OPTIONS 	= --address=$(ADDRESS) --split=4

WEBDIR		= kuepper@shell.sourceforge.net:/home/groups/p/py/pygsl/htdocs/reference


# LaTeX source files
SOURCES		= const.tex \
		copyright.tex \
		differentiation.tex \
		errors.tex \
		freedoc.tex \
		histogram.tex \
		ieee.tex \
		init.tex \
		install.tex \
		pygsl.tex \
		rng.tex \
		sf.tex \
		statistics.tex


# entry points

default:	pdf html # need something to generate a current index before html, PDF seems most useful

# some targets (noteably ps) remove the dvi, so make that last
all:		pdf html ps text dvi

dvi:		pygsl.dvi

html:		pygsl/pygsl.html

pdf:		pygsl.pdf

ps:		pygsl.ps.gz

text:		pygsl.txt.gz


web:		all
		@scp -r icons pygsl pygsl.dvi pygsl.pdf pygsl.ps.gz pygsl.txt.gz $(WEBDIR)


# some real targets

mkhowto:
		echo "You need to create a link to mkhowto,"
		echo "see the README for details."

pygsl/pygsl.html:	Makefile mkhowto $(SOURCES)
		$(MKHOWTO) --html $(OPTIONS) pygsl.tex

pygsl.dvi:	Makefile mkhowto $(SOURCES)
		$(MKHOWTO) --dvi $(OPTIONS) pygsl.tex

pygsl.pdf:	Makefile mkhowto $(SOURCES)
		$(MKHOWTO) --pdf $(OPTIONS) pygsl.tex

pygsl.ps.gz:	Makefile mkhowto $(SOURCES)
		$(MKHOWTO) --ps $(OPTIONS) pygsl.tex
		$(GZIP) pygsl.ps

pygsl.txt.gz:	Makefile mkhowto $(SOURCES)
		$(MKHOWTO) --text $(OPTIONS) pygsl.tex
		$(GZIP) pygsl.txt


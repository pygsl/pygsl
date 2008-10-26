# Makefile for PyGSL documentation
#
# Copyright (c) 2002-2005 Jochen Küpper
# Copyright (c) 2005 Sebastien Maret

# You could set this to letter:

PAPER = a4
PAPER = letter

PYTHON = python
DVIPS = dvips -N0 -t $(PAPER)

PWD = $(shell pwd)
TEXINPUTS = $(PWD)/commontex:

MKHOWTO = TEXINPUTS=$(TEXINPUTS) $(PYTHON) $(PWD)/mkhowto
MKHTML = $(MKHOWTO) --html --about html/stdabout.dat \
	--iconserver ../icons --favicon --dvips-safe

MKDVI = $(MKHOWTO) --paper=$(PAPER) --dvi
MKPDF =	$(MKHOWTO) --paper=$(PAPER) --pdf
MKPS= $(MKHOWTO) --paper=$(PAPER) --ps

DVIFILES = paper-$(PAPER)/ref.dvi
PDFFILES = paper-$(PAPER)/ref.pdf
PSFILES = paper-$(PAPER)/ref.ps

INDEXFILES = html/ref/ref.html

HTMLCSSFILES = html/ref/ref.css

ALLHTMLFILES=$(INDEXFILES)

ALLCSSFILES=$(HTMLCSSFILES)

# some information for generated html
MAILINGLIST	= pygsl@lists.sourceforge.net
ADDRESS		= ""
# Send comments to the <a href=\"mailto:$(MAILINGLIST)\">PyGSL community</a>."
OPTIONS 	= --address=$(ADDRESS) --split=4

WEBDIR		= schnizer,pygsl@web.sf.net:htdocs/reference/pygsl/
RSYNC = rsync

# PyGSL reference manual source files

REFFILES = ref/const.tex \
	ref/copyright.tex \
	ref/differentiation.tex \
	ref/errors.tex \
	ref/freedoc.tex \
	ref/histogram.tex \
	ref/ieee.tex \
	ref/init.tex \
	ref/install.tex \
	ref/ref.tex \
	ref/rng.tex \
	ref/sf.tex \
	ref/statistics.tex

# These must be declared phony since there
# are directories with matching names:

.PHONY: ref html

# Main target

default: html
all: html dvi ps pdf

dvi: $(DVIFILES)
pdf: $(PDFFILES)
ps: $(PSFILES)

# Rules to build PostScript and PDF formats

.SUFFIXES: .dvi .ps

.dvi.ps:
	$(DVIPS) -o $@ $<

# PyGSL Reference Manual

paper-$(PAPER)/ref.dvi: $(REFFILES)
	cd paper-$(PAPER) && $(MKDVI) ../ref/ref.tex

paper-$(PAPER)/ref.pdf: $(REFFILES)
	cd paper-$(PAPER) && $(MKPDF) ../ref/ref.tex

# Targets to convert the manuals to HTML using Nikos Drakos' LaTeX to
# HTML converter.  For more info on this program, see
# <URL:http://cbl.leeds.ac.uk/nikos/tex2html/doc/latex2html/latex2html.html>.
web : html
	 $(RSYNC) --exclude '*.pl' -e ssh -avz html/ref/ $(WEBDIR)

html: $(ALLHTMLFILES) $(HTMLCSSFILES)

$(ALLCSSFILES): html/style.css
	cp $< $@

ref: html/ref/ref.html html/ref/ref.css
html/ref/ref.html: $(REFFILES)
	$(MKHTML) --dir html/ref ref/ref.tex

# Housekeeping target

clean:
	rm -f $(DVIFILES) $(PSFILES) $(PDFFILES)
	rm -rf html/ref
	rm -f checkargs.pm html2texi.pl icons mkhowto mkinfo py2texi.el

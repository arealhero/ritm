BUILDDIR ?= build

PDFLATEX_FLAGS := -output-directory $(BUILDDIR)

SRC := src/report.tex

all: | $(BUILDDIR)
	@echo "Compiling report..."
	@pdflatex $(PDFLATEX_FLAGS) $(SRC) > /dev/null
	@pdflatex $(PDFLATEX_FLAGS) $(SRC) > /dev/null
	@cp $(BUILDDIR)/report.pdf .

$(BUILDDIR):
	@mkdir -p $(BUILDDIR) $(BUILDDIR)/data

clean:
	$(RM) -r $(BUILDDIR) data images

.PHONY: all clean


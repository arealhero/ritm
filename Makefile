H ?= 0.01
BUILDDIR ?= build
CMAKE_GENERATOR ?= "Unix Makefiles"

MAKEFLAGS += --no-print-directory

report: pics points
	@$(MAKE) -C docs

pics: csv
	@echo "Generating pictures from 'points.csv'..."
	@gnuplot -e "filename='$(BUILDDIR)/points.csv'" scripts/plot.gpi
	@mkdir -p docs/images
	@mv *.png docs/images

points: csv
	@echo "Converting 'points.csv' to 'points.tex'..."
	@scripts/points2tex $(H) $(BUILDDIR)/points.csv
	@mkdir -p docs/data
	@mv points.tex docs/data

csv: ode-num
	@echo "Generating 'points.csv'..."
	@cd $(BUILDDIR) && ./ode-num $(H)

ode-num:
	@echo "Building ode-num..."
	@cmake -G $(CMAKE_GENERATOR) -S . -B $(BUILDDIR) > /dev/null
	@cmake --build $(BUILDDIR) > /dev/null

clean:
	$(RM) -r $(BUILDDIR)
	@$(MAKE) -C docs clean

.PHONY: report ode-num points clean


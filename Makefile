.PHONY: flerp clean
flerp:
	@echo Du vill nog inte göra make i den här katalogen
	@echo om du inte tänker göra \'make clean\'
clean:
	cd fraction && $(MAKE) clean
	cd mystring && $(MAKE) clean
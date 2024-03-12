GO ?= go
GOFILES := $(shell find . -name "*.go" -type f)

.PHONY: test
test: $(GOFILES)
	@$(GO) test -v -cover

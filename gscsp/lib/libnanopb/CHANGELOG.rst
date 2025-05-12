Nano Protobuf (libnanopb)
=========================

**1.3.1 (2020-01-22)**

- Improvement: Hardcoded PB_FIELD_16BIT in public pb.h, instead of hardcoding it through Waf (solves bitbake issue).
- Improvement: Removed GomSpace introduced 'nanopb' scope of header files - auto-generated protobuf code doesn't use this scope (bitbake).

**1.2.2 (2019-10-16)**

- Feature: Added support for CPP output.

**1.2.1 (2019-04-09)**

- Improvement: Updated dependencies.

**1.1.1 (2019-02-26)**

- Feature: Added support for Python output, handler: nano_proto_gen_1_1.
- Feature: Added support for Markdown documentation output, handler: nano_proto_gen_1_1

**1.0.1 (2018-12-19)**

- Improvement: Updated documentation.

**1.0.0 (2018-11-21)**

- Improvement: Updated documentation and added license.

**0.1.2 (2018-08-14)**

- Feature: Nanopb version 0.3.9 imported.
- Feature: Nanopb plugins for proto->c conversion.

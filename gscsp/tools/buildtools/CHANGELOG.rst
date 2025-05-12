Buildtools (buildtools)
=======================

**2.11.3 (2020-04-21)**

- Improvement: Updated internal tools.
- Improvement: All document types now include the signoff box with revision details

**2.11.2 (2020-03-18)**

- Improvement: Updated build containers.

**2.11.1 (2020-03-10)**

- Improvement: Updated internal tools (bitnake builds).
- Improvement: Updated build containers.
- Improvement: Changed default Linux compiler and unit tests to Ubuntu 18.04, GCC 7.3.
- Breaking: Removed scripts for generating Eclipse files.

**2.10.4 (2020-01-21)**

- Improvement: Updated internal tools (bitbake builds).
- Improvement: Updated build containers.
- Feature: Added support for STM32L431 chip.

**2.10.3 (2019-12-03)**

- Improvement: Updated build containers.
- Breaking: Changed default naming of dist. tar.gz files to use GiT repo name.

**2.10.2 (2019-11-13)**

- Improvement: Updated internal tools.

**2.10.1 (2019-10-16)**

- Improvement: Updated build containers, includes new toolchain for AVR32/A3200.
- Improvement: Updated Waf from 2.0.17 to 2.0.18.

**2.9.1 (2019-07-03)**

- Breaking: Renamed linux build part "x86_64-gcc-7.3" to "x86_64-gcc-7".
- Improvement: Updated build containers, changed GCC for part="x86_64-gcc-7" from 7.3.0 to 7.4.0.
- Improvement: Updated Waf from version 2.0.9 to 2.0.17.
- Feature: Added support for changelog tag "Limitation".

**2.8.5 (2019-06-11)**

- Improvement: Changed disclaimer (in document templates) to regular chapter.

**2.8.4 (2019-05-24)**

- Feature: Changed order of reading version information, try VERSION file before GiT.

**2.8.3 (2019-05-16)**

- Improvement: If no version information available, try read file VERSION.

**2.8.2 (2019-04-10)**

- Improvement: Internal changes

**2.8.1 (2019-04-08)**

- Improvement: Internal changes to documentation

**2.8.0 (2019-04-03)**

- Improvement: Adding support for building to Ubuntu 18.04
- Improvement: Adding support for building unit tests in 32 bit

**2.7.0 (2019-02-28)**

- Improvement: Add support for BibTeX in documentation
- Improvement: Adding support for python unit tests
- Improvement: Updated documentation to be in line with newest template

**2.6.5 (2018-12-19)**

- Bug: keep dependency towards libgscsp / libcsp when building through bitbake.
- Improvement: Updated documentation.

**2.6.4 (2018-11-26)**

- Bug: Fixed 'status', causing warning about wrong versions.
- Improvement: Added check 'status' for multiple unique/checkout keys: sha/min_version/branch

**2.6.2 (2018-11-21)**

- Feature: Allow 'master' branches to use 'release-' branches (disabled check).

**2.6.1 (2018-11-14)**

- Feature: Added more specialized functions for generating SDK and Product manuals (confidentiality classification is set to empty).

**2.5.1 (2018-10-10)**

- Feature: Better docker building support. Force docker on/off, mount entire workspace, bind to specific version of image.

**2.4.2 (2018-08-13)**

- Breaking: removed option "--manifest-file" from command "gitinfo". Generate internal and external manifests.
- Feature: updated Waf, 1.9.7 -> 2.0.9.

**2.3.1 (2018-05-30)**

- Breaking: changed arguments/inputs for gs_doc::doxygen, changed to lists or Waf environment.
- Feature: added gs_add_doxygen() to support building API documentation for multiple modules.

**2.1.2 (2018-04-18)**

- Feature: added gs_gcc.gs_recurse() and gs_gcc.gs_recurse_unit_test().
- Feature: gs_doc.add_task_doc: added support for generating API documentation, using doxygen.
- Breaking: gs_test_cmocka: removed 'skipping build' in case of missing use relations.

**2.0.1 (2018-03-14)**

**1.0.0 (2017-06-23)**

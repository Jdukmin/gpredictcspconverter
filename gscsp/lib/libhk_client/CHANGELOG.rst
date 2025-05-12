Housekeeping System (libhk_client)
==================================

**4.5.2 (2019-10-16)**

- Feature: In parser, added support for parsing legacy (GOMX4) beacon types.
- Improvement: In parser, adding info log line for each beacon received.

**4.5.1 (2019-07-01)**

- Breaking: In parser, parameter callback now returns a list of value,index tuples instead of a list of values.
- Feature: In parser, support for having an array_index value of a single index instead of a range (LIBHK-117).

**4.4.1 (2019-05-20)**

- Improvement: In parser, beacons will now be offset if older than 10 years.
- Improvement: In parser, user can now add beacon time offsets + new offsets will be 'written' back to user.
- Improvement: In parser, satellite id is now also used when looking up beacon time offsets.
- Feature: It is now possible to tweak burst_idle_time and burst_size in commands and in the API.

**4.3.1 (2019-04-10)**

- Improvement: Updated dependencies.

**4.2.3 (2019-04-10)**

- Improvement: Added new option to examples

**4.2.2 (2019-04-08)**

- Bug: fixing request of file-based telemetry.
- Bug: fixing issue when using t0=0 in requests.

**4.2.1 (2019-02-26)**

- Breaking: Moved host commands to libhk.
- Improvement: Improved beacon file loader.

**4.1.4 (2019-01-29)**

- Improvement: Removed files not used by the client (parameter files).

**4.1.3 (2018-12-20)**

- Improvement: Updated documentation.
- Bug: Fixed issue with logging in python parser.

**4.1.2 (2018-12-03)**

- Improvement: Fixed commands documentation

**4.1.1 (2018-11-22)**

- Feature: Added flag to completely enable/disable the Housekeeping Server.
- Breaking: Renamed root Command to better match overall scheme (hk_client -> hk, hk -> hk_srv).
- Feature: Added Command for asking Housekeeping Server to reload its configuration.
- Feature: Adding option to request beacon from old hksrv (command, and python bindings).

**4.0.1 (2018-10-17)**

- Feature: The client is now in a seperate repository.

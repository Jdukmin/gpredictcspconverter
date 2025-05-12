Remote GOSH (librgosh_client)
=============================

**1.2.3 (2020-03-24)**

- Bug: Initialized error code, that may not be written to in case of framework error.

**1.2.2 (2020-03-18)**

- Improvement: Updated documentation and example code.

**1.2.1 (2020-01-23)**

- Bug: Fixed formatting issue in 'rgosh server' command.
- Improvement: Updated dependencies.

**1.1.3 (2019-10-16)**

- Bug: Reduced max CSP package size from 226 to 180 bytes, so it can be send via the AX100.

**1.1.2 (2019-05-19)**

- Improvement: Updated dependencies.

**1.1.1 (2019-04-10)**

- Improvement: Increased client timeout and improved debug logs.

**1.0.2 (2019-01-28)**

- Improvement: Register all used log groups.

**1.0.1 (2018-12-19)**

- Improvement: Updated documentation.

**1.0.0 (2018-11-21)**

- Feature: Added support for RGOSH client/server communication over CSP-RDP connection.
- Breaking: RGOSH port has been changed from the GSCRIPT port to it's own dedicated RGOSH port.
- Breaking: Updated/Improved the RGOSH protobuf messages.
- Improvement: More responses supported per request - Allows extensive data to be transferred.

**0.1.2 (2018-08-14)**

- Feature: RGOSH client API
- Feature: RGOSH python bindings.
- Feature: Run GOSH commands on remote CSP nodes - Results/output supported. 
- Feature: RGOSH communication with RGOSH server using RGOSH protobuf messaging.

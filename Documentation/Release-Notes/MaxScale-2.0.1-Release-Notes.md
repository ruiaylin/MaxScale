# MariaDB MaxScale 2.0.1 Release Notes

Release 2.0.1 is a GA release.

This document describes the changes in release 2.0.1, when compared to
release 2.0.0.

If you are upgrading from 1.4.3, please also read the release notes
of [2.0.0](./MaxScale-2.0.0-Release-Notes.md).

For any problems you encounter, please consider submitting a bug
report at [Jira](https://jira.mariadb.org).

## New Features

### MaxAdmin Usage

In 2.0.0 (Beta), the authentication mechanism of MaxAdmin was completely
changed, so that MaxAdmin could only connect to MaxScale using a Unix domain
socket, thus _only when run on the same host_, and authorization was based
on the Unix identity. Remote access was no longer supported.

To the user this was visible so that while you in 1.4.3 had to provide
a password when starting _maxadmin_ and when adding a user
```
MaxAdmin> add user john johns-password
```
In 2.0.0 (Beta), where only Unix domain sockets could be used, you did not
have to provide a password neither when starting _maxadmin_, nor when adding
users
```
MaxAdmin> add user john
```
as the MaxScale user corresponded to a Unix user.

In 2.0.1 (GA) this has been changed so that the 1.4.3 behaviour is intact
but deprecated, and the 2.0.0 (Beta) behaviour is exposed using a new set
of commands:
```
MaxAdmin> enable account alice
MaxAdmin> disable account alice
```

Note that which mechanism is available depends upon how the MaxAdmin
listener has been configured in the MaxScale configuration file.

Please consult
[MaxAdmin documentation](../Reference/MaxAdmin.md) for more details.

## Bug fixes


## Known Issues and Limitations

There are some limitations and known issues within this version of MaxScale.
For more information, please refer to the [Limitations](../About/Limitations.md) document.

## Packaging

RPM and Debian packages are provided for the Linux distributions supported
by MariaDB Enterprise.

Packages can be downloaded [here](https://mariadb.com/resources/downloads).

## Source Code

The source code of MaxScale is tagged at GitHub with a tag, which is identical
with the version of MaxScale, prefixed with _maxscale_.

For instance, the tag of version X.Y.Z of MaxScale
is _maxscale-X.Y.Z_.

The source code is available [here](https://github.com/mariadb-corporation/MaxScale)

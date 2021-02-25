# Unid-System [![Build Status]

This is the `README` file for new versio.



```
git clone https://github.com/Subsurface-divelog/subsurface.git
```

You can also fork the repository and browse the sources at the same site,
simply using https://github.com/Subsurface-divelog/subsurface


```
$ ./subsurface
```

On Mac:

```
$ open Subsurface.app
```

Native builds on Windows are not really supported (the official Windows
installers are both cross-built on Linux).

You can give a data file as command line argument, or (once you have
set this up in the Preferences) Subsurface picks a default file for
you when started from the desktop or without an argument.

If you have a dive computer supported by libdivecomputer, you can just
select "Import from Divecomputer" from the "Import" menu, select which
dive computer you have (and where it is connected if you need to), and
hit "OK".

The latest list of supported dive computers can be found in the file
SupportedDivecomputers.txt.

Much more detailed end user instructions can be found from inside
Subsurface by selecting Help (typically F1). When building from source
this is also available as Documentation/user-manual.html. The
documentation for the latest release is also available on-line
http://subsurface-divelog.org/documentation/

## Contributing


The body of the commit message can be several paragraphs, and
please do proper word-wrap and keep columns shorter than about
74 characters or so. That way "git log" will show things
nicely even when it's indented.

Make sure you explain your solution and why you're doing what you're
doing, as opposed to describing what you're doing. Reviewers and your
future self can read the patch, but might not understand why a
particular solution was implemented.

Reported-by: whoever-reported-it
Signed-off-by: Your Name <you@example.com>
```

where that header line really should be meaningful, and really should be
just one line.  That header line is what is shown by tools like gitk and
shortlog, and should summarize the change in one readable line of text,
independently of the longer explanation. Please use verbs in the
imperative in the commit message, as in "Fix bug that...", "Add
file/feature ...", or "Make Subsurface..."

## A bit of Subsurface history

In fall of 2011, when a forced lull in kernel development gave him an
opportunity to start on a new endeavor, Linus Torvalds decided to tackle
his frustration with the lack of decent divelog software on Linux.

Subsurface is the result of the work of him and a team of developers since
then. It now supports Linux, Windows and MacOS and allows data import from
a large number of dive computers and several existing divelog programs. It
provides advanced visualization of the key information provided by a
modern dive computer and allows the user to track a wide variety of data
about their diving.

In fall of 2012 Dirk Hohndel took over as maintainer of Subsurface.

ll1gen
======

A bean generator with JSON deserializer / serializer capabilities built-in.
In place deserialize (i.e. you do not create other structs / classes). 

Implementation: RFC 4627, only objs and vectors can be roots.

Usage is very simple: 
  1. Write a spec file for your beans
  2. Run ll1gen over them
  <LL1GENHOME>/bin/ll1gen -h <LL1GENHOME> -f <SPECFILE> -d <DESTINATIONDIR>
  This will generate the classes.
  3. Use them in your code using usual stream operators '<<' '>>'

Specification file
======
A spec file is a text file with the following content:

namespace test
namespace nested
namespace detail

// this will generate namespace test { namespace nested { namespace detail {

//Simple bean definition
class PreviouslyDefinedBean
  funny_name	string
  not_suitable	bool

//next, the class definition, something like:
class ClassName
  optionalName 	* string 
  mandatoryName   string 
  boolValue 	  bool
  optionalBV    * bool
  a_number	  int
  a_number	  unsigned int
  vectorBool	+ bool
  vectorString	+ string
  vectorNmbs	+ double
  vectorObj	+ PreviouslyDefinedBean
  boolVec       +* bool
  stringVec     +* string
  intVec        *+ int
  objVec        *+ PreviouslyDefinedBean

//end


Fields marked with '*' have the capability to treat nulls. 
Fields marked with '+' are vectors. 
Fields marked with both are vectors with null capabilities.

Usage
======
After you generate the bean .hpp file, all you have to do is to include and use it:

#include "classname.hpp"

.....

ClassName cn;

in >> cn;
out << cn;

What's next?
======

While this looks like it is working, this little piece of software is still in its infancy. Use it on your own risk.

1. Tests. More tests.
2. Removing some idiotic code (hurry) & create routines for some other duplicated code
3. Documentation ... (always a pleasure)

No pretty printing will be added. Use an editor that knows how to format JSON

ll1gen
======

A bean generator with JSON deserializer / serializer capabilities built-in.
In place deserialize (i.e. you do not create other structs / classes). 

Implementation: RFC 4627, only objs and vectors can be roots.  

Build is based on cmake so you should know how to deal with it.  

Usage is very simple: 
  1. Write a spec file for your beans
  2. Run ll1gen over them
  LL1GENHOME/bin/ll1gen -h LL1GENHOME -f SPECFILE -d DESTINATIONDIR
  This will generate the classes.
  3. Use them in your code using usual stream operators '<<' '>>'

##Rationale##

I was looking for a JSON library that was:  
1. Reasonably fast, and with a low memory consumption  
2. Multi-thread safe  
3. Streamable objects  
4. Safe to use: maintained, etc.  

I couldn't find one, so I thought: I didn't like them anyway.  
Most of them were using additional objects (Like JsonAttr, JsonObject, etc) instead of the object itself. So I decided to write a small JSON bean generator. It takes a definition of the bean and 'writes' JSON serializers and deserializers in .hpp files. Users will not copy data in their own business objects, but use the already generated beans for that. From this point of view, it should be pretty fast and memory friendly, although perf testing is out of my scope right now.

##Features##
* No API to understand. JSON serialization/deserialization of the objects is natural.  
* Header only, no dependencies  
* Footprint is, I believe, pretty small since no special structs / classes are used. 
 


## Specification file ##

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
  
  //end of spec file


Fields marked with '*' have the capability to treat nulls.  
Fields marked with '+' are vectors.   
Fields marked with both are vectors with null capabilities.  

## Usage ##

Note: You have some tests in the tests directory. That should clarify things.

After you generate the bean .hpp file, all you have to do is to include and use it:

  #include "classname.hpp"  

  .....  

  ClassName cn;  

  in >> cn;  

  out << cn;  


## What's next? ##

1. Review generated code
2. Documentation ... (always a pleasure). Add example code on how to parse arrays.
3. Check it on Windows systems ... although it should be fine.

No pretty printing will be added. Use an editor that knows how to format JSON

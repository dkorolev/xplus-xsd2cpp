`XmlPlus xsd2cpp` provides "simple to use" C++ XML data-binding through W3C XML-Schema.

`XmlPlus xsd2cpp`, is an _open_ _source_, **free** tool.

The `XmlPlus` package comes with an "XML Schema to C++ Data Binding compiler" viz. **xsd2cpp**.

The `xsd2cpp` binary when invoked on a XML-Schema file, generates:

  * the C++ sources/headers for the supplied XML-Schema
  * a main.cpp template, to demonstrate how generated sources can be consumed
  * the automake/autoconf files for building the generated source


The main.cpp file along with generated C++ source, is built into a `[input]run` binary for an `[input].xsd` input, which can be used to:
  * generate sample xml documents, without any custom(additional) C++ code
  * validate an instance xml document against the Schema `[input].xsd`, without any custom(additional) C++ code
  * generate populated instance xml document, if you write code in the callback function inside main.cpp to populate the Document.
  * option to roundtrip ie. read and instance xml file into C++ structures, and then write back to xml


A brief note on `XmlPlus xsd2cpp`:
  * provides C++ Data-Binding, validating-parser, writer for xml-files constrained by the supplied XML-schema
  * roundtrip retains comments and processing instructions
  * contains good examples to demonstrate usage
  * tested against some of randomly selected W3C test cases


Currently Supported Platforms(OS):

  * Linux : Ubuntu, Fedora, Redhat and other flavours of Linux
  * Mac OS X


Currently Supported Encodings:

  * ASCII
  * UTF-8
  * ISO-8859-1
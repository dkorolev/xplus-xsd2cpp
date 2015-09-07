## Introduction ##

`XmlPlus` is a C++ XML Data Binding Tool.
`XmlPlus` provides following utilities:
  * X/O mapping:  `XmlPlus xsd2cpp` automatically generates C++ classes mapped to XML-Schema components. The in-memory objects holding xml data are also known as XML-Objects. The applications interact with xml data directly through in-memory objects, rather than using DOM/SAX APIs.
  * Parsing ie. Deserialization/Unmarshalling
  * Parser to read valid XML documents into in-memory XML-Objects
  * Marshalling/Serialization: Writer to write the XML-Objects to xml files

An application using xsd2cpp generated C++ classes(XML-Objects), has to interact only with readymade in-memory object-interface. These objects hide(and save) all the complexities of XML I/O from(for) the application. Thus, one is saved from writing XML I/O implementations(ie. Classes to hold xml data, alongwith Serialization/Deserialization code) for xml data.


## About xsd2cpp ##

The xsd2cpp tool is a C++ code generator. The xsd2cpp tool when invoked on an input XML Schema, generates C++ classes(headers) mapped to the input XML Schema components. Alongside, wherever needed, it generates implementation files(.cpp) for the generated C++ classes. Also, a sample application(main.cpp) is generated to show how an application could consume the generated C++ source files.


## Why choose `XmlPlus` ##
Here are a few reasons for using `XmlPlus`:
  * `XmlPlus` is open-source and free.
  * It provides a code generator viz. xsd2cpp. The xsd2cpp tool generates C++ Data Binding code(XML-Objects) for the supplied schema.
  * It provides "simple to use" C++ XML data binding.
  * The generated code when built into a `[input]`run binary, can be used to generate good sample xml documents, validate xml documents, xml I/O ie. serialization/deserialization etc.
  * `XmlPlus xsd2cpp` is a nework-enabled processor.
  * Deserialization has in-built validation.
  * `XmlPlus` retains not just elements and attributes but also processing-instructions and comments, across roundtrips. Here roundtrip refers to the typical tests of reading a xml document into data-binding objects(in memory) and then writing them back to a xml document.
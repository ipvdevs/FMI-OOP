#include <cassert>
#include <iostream>

#include "Document.hpp"
#include "KeyValueDatabase.hpp"

void testDocument()
{
    std::string docName = "testDoc";
    std::string docLocation = "2";
    std::string docExtension = "doc";
    Document doc = Document(docName, docLocation, docExtension);

    assert(doc.get_name() == docName);
    assert(doc.get_location() == docLocation);
    assert(doc.get_extension() == docExtension);
    assert(doc.get_fullpath() == "2/testDoc.doc");

    std::string line1 = "line1";
    doc.write_line(line1);
    assert(doc.read_line(1) == line1);

    Document anotherDoc = Document("doc", "src", "doc");

    anotherDoc.write_line(line1);

    assert(anotherDoc == &doc);

    anotherDoc.write_line("This is an example doc");
    anotherDoc.write_line("This is another example line");
    anotherDoc.write_line("This is a third example line");
    anotherDoc.write_line("This is a forth example line");

    std::cout << anotherDoc.debug_print();

    Document temp("temp", "/tmp", "doc");

    temp.write_line("This is an example doc");
    temp.write_line("This is another example line");
    temp.write_line("This is a third example line");
    temp.write_line("This is a forth example line");

    std::cout << temp.read_line() << std::endl;
    std::cout << temp.read_line() << std::endl;
    std::cout << temp.read_line(3) << std::endl;
    std::cout << temp.read_line() << std::endl;

    std::cout << temp.read_line(1) << std::endl;
    std::cout << temp.read_line() << std::endl;

    std::cout << "debug print:\n";
    std::cout << temp.debug_print() << std::endl;
    std::cout << "To string:\n";

    std::string serData = temp.to_string();

    Document docSerialized("", "", "");
    docSerialized.from_string(serData);

    std::cout << docSerialized.to_string();
}

void testKeyValueDatabase()
{
    KeyValueDatabase kvdb("kvdb", "HW_4/2/", "db");

    std::pair<std::string, int> p1("p1", 1);
    std::pair<std::string, int> p2("p2", 2);
    std::pair<std::string, int> p3("p3", 3);

    kvdb.add_entry(p1);
    kvdb.add_entry(p2);
    kvdb.add_entry(p3);

    assert(kvdb.get_value("p2") == 2);

    Object *kvdbClone = kvdb.clone();

    assert(kvdb == kvdbClone);

    std::cout << kvdbClone->debug_print();
    std::string kvdbSerialized = kvdbClone->to_string();

    KeyValueDatabase deSerialization("", "", "");
    deSerialization.from_string(kvdbSerialized);

    assert(deSerialization == &kvdb);

    delete kvdbClone;
}

int main()
{

    // testDocument();
    testKeyValueDatabase();

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class HTMLElemen{
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;
    virtual string Render() = 0;
    virtual HTMLElemen* duplicate() = 0;
    virtual ~HTMLElemen(){}
};

class HTMLButtonElement : public HTMLElemen{
public:
    const string& Title() const;
    string Render() override{
        return "<button>title-of-the-button</button>\n";
    }
    HTMLElemen* duplicate()
    {
        return new HTMLButtonElement(*this);
    }
};

class HTMLImageElement : public HTMLElemen{
public:
    const string& Url() const;
    string Render() override{
        return "<img src=\"../../smiley.gif\" height=\"42\" width=\"42\">\n";
    }
    HTMLElemen* duplicate()
    {
        return new HTMLImageElement(*this);
    }
};

class HTMLTextAreaDocument : public HTMLElemen{
public:
    const string& Content() const;
    string Render() override{
        return "<textarea>\ncontent-of-the-text-area\n</textarea>\n";
    }
    HTMLElemen* duplicate()
    {
        return new HTMLTextAreaDocument(*this);
    }
};


int main(int argc, char *argv[])
{
    HTMLElemen* a1 = new HTMLButtonElement;
    HTMLElemen* a2 = new HTMLImageElement;
    HTMLElemen* a3 = new HTMLTextAreaDocument;
    HTMLElemen* a12 = a1->duplicate();
    HTMLElemen* a22 = a2->duplicate();
    HTMLElemen* a32 = a3->duplicate();

    cout << a12->Render();
    cout << a22->Render();
    cout << a32->Render();

    delete a1;
    delete a2;
    delete a12;
    delete a22;
    delete a3;
    delete a33;

    return 0;
}

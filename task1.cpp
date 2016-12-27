#include <iostream>

using namespace std;

class HTMLElemen{
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;
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
    HTMLElemen *p;
    HTMLButtonElement obj1;
    HTMLImageElement obj2;
    HTMLTextAreaDocument obj3;
    p = &obj1;
    cout << p->Render();
    p =&obj2;
    cout << p->Render();
    p =&obj3;
    cout << p->Render();
    delete p;
    return 0;
}

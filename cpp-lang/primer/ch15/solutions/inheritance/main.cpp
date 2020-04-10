#include <iostream>

class Base {
public:
    void pub_mem() {}
protected:
    int prot_mem() {}
private:
    char priv_mem() {}
};

class Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; }
};

class Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};

class Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};

class Derived_From_Public : public Pub_Derv {
    void memfcn(Base &b) { b = *this; }
};

class Derived_From_Protected : public Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};

class Derived_From_Private : public Priv_Derv {
//    void memfcn(Base &b) { b = *this; } // Derived_From_Private is an inaccessible
};

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_From_Public dd1;
    Derived_From_Private dd2;
    Derived_From_Protected dd3;

    Base *p = &d1; // OK
//    p = &d2; // Priv_Derv is an inaccessible
//    p = &d3; // Prot_Derv is an inaccessible
    p = &dd1;  // OK
//    p = &dd2;  // Derived_From_Private is an inaccessible
//    p = &dd3;  // Derived_From_Protected is an inaccessible

    return 0;
}

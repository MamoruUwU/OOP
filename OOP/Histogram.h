#pragma once
#include <iostream>


class A { int a; };
class B : public A { int b; };
class C : public A { int c; };
class D : public B { int d; };
class E : public B { int e; };
class F : public C { int f; };
class G : public C { int g; };
class H : public E, public F { int h; };

class VA { int va; };
class VB : virtual public VA { int vb; };
class VC : virtual public VA { int vc; };
class VD : virtual public VB { int vd; };
class VE : virtual public VB { int ve; };
class VF : virtual public VC { int vf; };
class VG : virtual public VC { int vg; };
class VH : virtual public VE, public VF { int vh; };
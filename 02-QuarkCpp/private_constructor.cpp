// si no se define como publico, es privado

class E{
// public:
    E(){};
    friend int main();
};

int main(){
    E e; //Error si no se define publico el constructor o se define main como amiga
    return 0;
}
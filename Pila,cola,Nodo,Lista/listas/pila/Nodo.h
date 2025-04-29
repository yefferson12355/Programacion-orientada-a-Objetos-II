template <class T>
class Nodo{
    private:
        T dato;
        Nodo<T> *sig;
    public:
        Nodo(T v){
            dato = v;
            sig = NULL;
        }

        Nodo(){}

        Nodo<T> *retSig(){
            return sig;
        }
        T retDato(){
            return dato;
        }
        void unirCon(Nodo<T> *n){
            sig = n;
        }
};

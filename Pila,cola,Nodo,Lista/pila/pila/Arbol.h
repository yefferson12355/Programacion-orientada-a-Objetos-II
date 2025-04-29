template <class T>
class Arbol{
    private:
        Nodo<T> *raiz;
    public:
        Arbol(){
            raiz = NULL;
        }
        void Insertar(T v){
            Nodo<T> *n = new Nodo<T>(v);
            if(raiz == NULL)
                raiz = n;
            else
                Insertar(raiz, n);
        }
        void inOrden(){
            inOrden(raiz);
        }
        void postOrden(){
            postOrden(raiz);
        }
    protected:
        void Insertar(Nodo<T> *r, Nodo<T> *n){
            //! lado izquierdo
            if(  r->retDato() > n->retDato() ){
                if(r->retHijoIzq() == NULL)
                    r->unirConIzq(n);
                else
                    Insertar(r->retHijoIzq(), n);
            }
            //! lado derecho
            if(  r->retDato() < n->retDato() ){
                if(r->retHijoDer() == NULL)
                    r->unirConDer(n);
                else
                    Insertar(r->retHijoDer(), n);
            }
        }
        void inOrden(Nodo<T> *r){
            if(r != NULL)
            {
                inOrden(r->retHijoIzq());
                cout<<r->retDato()<<" ";
                inOrden(r->retHijoDer());
            }
        }

        void postOrden(Nodo<T> *r){
            if(r != NULL)
            {
                postOrden(r->retHijoIzq());
                postOrden(r->retHijoDer());
                cout<<r->retDato()<<" ";
            }
        }
};

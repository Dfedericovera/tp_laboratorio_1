using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ej_31_guia2017
{
    class Negocio
    {
        public PuestoAtencion caja;
        private Queue<Cliente> clientes;
        private string nombre;
        private Negocio() 
        {
           clientes  = new Queue<Cliente>();

        }
        public Negocio(string nombre)
        {
            this.nombre = nombre;
        }

        public Cliente Cliente
        {
            get
            {
                return clientes.Dequeue();
            }
            set
            {
                clientes.Enqueue(value);
            }
        }

        //public bool operator !=(Negocio n, Cliente c)
        //{

        //}


    }
}

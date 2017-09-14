using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ej_31_guia2017
{
    class Cliente
    {
        private string nombre;
        private int numero;

        public Cliente (int numero) 
        {
            this.numero = numero;
        }
        public Cliente(int numero, string nombre)
        {
            this.numero = numero;
            this.nombre = nombre;
        }

        public string Nombre
        {
            get
            {
                return this.nombre;
            }
            set
            {
                this.nombre = value;
            }
        }

        public int Numero
        {
            get
            {
                return this.numero;
            }
            set
            {
                this.numero = value;
            }
        }

        public static bool operator !=(Cliente c1, Cliente c2)
        {
            bool retValue = true;
            if (c1.numero == c2.numero)
            {
                retValue = false;
            }
            return retValue;
        }
        public static bool operator ==(Cliente c1, Cliente c2)
        {
            bool retValue = false;
            if (c1.numero == c2.numero)
            {
                retValue = true;
            }
            return retValue;
        }


    }
}

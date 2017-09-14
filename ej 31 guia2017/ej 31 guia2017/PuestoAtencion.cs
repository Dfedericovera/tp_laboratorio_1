using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ej_31_guia2017
{
    class PuestoAtencion
    {
        private static int numeroActual;
        private Puesto puesto;

        public enum Puesto {caja1, caja2}

        static PuestoAtencion() 
        {
            numeroActual = 0;
        }
        public PuestoAtencion (Puesto puesto)
        {
            this.puesto = puesto;
        }
        public static int NumeroActual
        {
            get
            {
                numeroActual++;
                return numeroActual;
            }
        }
        public bool Atender(Cliente cli)
        {
            Thread.Sleep(2000);
            return true;
        }

    }
}

﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LIBRERIA_RECO
{
    public partial class ASISTENTE : Form
    {
        public ASISTENTE()
        {
            InitializeComponent();
        }

        // Definición de variables globales
        // Privadas

        // Panel principal donde se visualizan controles para la seguridad,
        // aire acondicionado, televisión y control de puertas
        private PGeneral pgeneral = new PGeneral();
        // Panel para controlar todas las luces de la casa
        private PLuces pluces = new PLuces();
        // Panel para controlar el asistente
        AsistenteInterfaz asistenteInterfaz1 = new AsistenteInterfaz();

        /* Funciones del desarrollador */

        // Limpiara el formulario
        void quitarControles()
        {
            pContenedor.Controls.Remove(pgeneral);
            pContenedor.Controls.Remove(pluces);
        }

        // Carga las propiedades a los paneles principales
        void valoresDefault()
        {
            // Se adaptan con todo el ancho y el alto de su contenedor padre
            asistenteInterfaz1.Dock = DockStyle.Bottom;
            pgeneral.Dock = DockStyle.Fill;
            pluces.Dock = DockStyle.Fill;
        }

        private void close_Click(object sender, EventArgs e)
        {
             Application.Exit(); // Cierra formulario
        }

        private void general_Click(object sender, EventArgs e)
        {
            // Llama a panel general al formulario principal
            quitarControles();
            pContenedor.Controls.Add(pgeneral);
        }

        private void luces_Click(object sender, EventArgs e)
        {
            // Llama a panel luces al formulario principal
            quitarControles();
            pContenedor.Controls.Add(pluces);
        }

        private void ASISTENTE_Load(object sender, EventArgs e)
        {
            // Llama a panel luces al formulario principal cuando carga por primera vez
            pContenedor.Controls.Add(pgeneral);

            valoresDefault();
            pContenedor.Controls.Add(asistenteInterfaz1);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2_2_P
{
    class PNT
    {
        private double x = 0;
        private double y = 0;

        public double X { get { return x; } set { if (isCoordinateValid(value)) x = value; } }
        public double Y { get { return y; } set { if (isCoordinateValid(value)) y = value; } }

        public PNT(double xInit, double yInit)
        {
            X = xInit;
            Y = yInit;
        }

        public PNT(PNT copyPoint) : this(copyPoint.x, copyPoint.y) { }

        private bool isCoordinateValid(double coord) { return !double.IsNaN(coord) && !double.IsInfinity(coord); }

        public override string ToString()
        {
            return "(" + x + ";" + y + ")";
        }
    }
}

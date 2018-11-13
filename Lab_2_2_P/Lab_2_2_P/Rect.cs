using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2_2_P
{
    class Rect
    {
        private double width;
        private double height;

        private PNT LT_PNT;
        private PNT RB_PNT;
        private PNT center;

        public PNT LeftTop { get { return new PNT(LT_PNT); } }
        public PNT RightTop { get { return new PNT(RB_PNT.X, LT_PNT.Y); } }
        public PNT RightBottom { get { return new PNT(RB_PNT); } }
        public PNT LeftBottom { get { return new PNT(LT_PNT.X, RB_PNT.Y); } }
        public PNT Center { get { return new PNT(center); } }
        public double Width { get { return width; } }
        public double Height { get { return height; } }

        public Rect(PNT LeftTop, PNT RightBottom)
        {
            if (LeftTop == null || RightBottom == null)
            {
                LT_PNT = new PNT(0, 0);
                RB_PNT = new PNT(0, 0);
                center = new PNT(0, 0);
                width = 0;
                height = 0;
                return;
            }

            LT_PNT = new PNT(Math.Min(LeftTop.X, RightBottom.X), Math.Max(LeftTop.Y, RightBottom.Y));
            RB_PNT = new PNT(Math.Max(LeftTop.X, RightBottom.X), Math.Min(LeftTop.Y, RightBottom.Y));
            center = new PNT((LT_PNT.X + RB_PNT.X) / 2, (LT_PNT.Y + RB_PNT.Y) / 2);

            width = RB_PNT.X - LT_PNT.X;
            height = LT_PNT.Y - RB_PNT.Y;
        }

        public Rect(Rect copyRect) : this(copyRect.LT_PNT, copyRect.RB_PNT) { }

        public bool isPointInside(PNT P)
        {
            return P.X >= LT_PNT.X && P.X <= RB_PNT.X && P.Y >= RB_PNT.Y && P.Y <= LT_PNT.Y;
        }

        public bool isIntersects(Rect R)
        {
            return isPointInside(R.LeftTop) || isPointInside(R.LeftTop) || isPointInside(R.RightBottom) || isPointInside(R.LeftTop);
        }

        public void setScale(double scale)
        {
            if (scale == 0)
                return;

            LT_PNT = new PNT(center.X - (center.X - LT_PNT.X) * scale, center.Y + (LT_PNT.Y - center.Y) * scale);
            RB_PNT = new PNT(center.X + (RB_PNT.X - center.X) * scale, center.Y - (center.Y - RB_PNT.Y) * scale);

            width = RB_PNT.X - LT_PNT.X;
            height = LT_PNT.Y - RB_PNT.Y;
        }

        public void moveTo(double xNew, double yNew)
        {
            center = new PNT(xNew, yNew);
            LT_PNT = new PNT(xNew - width / 2, yNew + height / 2);
            RB_PNT = new PNT(xNew + width / 2, yNew - height / 2);
        }

        public void Draw(char symbol)
        {
            Console.WriteLine(ToString());

            if ((int)height == 0)
                return;

            string cap = new string(symbol, (int)width);
            Console.WriteLine(cap);

            if ((int)height == 1)
                return;

            for (int i = 1; i < height - 1; i++)
                Console.WriteLine(symbol + (new string(' ', (int)width - 2)) + symbol);

            Console.WriteLine(cap);
        }

        public static Rect operator *(Rect R, double scale)
        {
            Rect RCopy = new Rect(R);
            RCopy.setScale(scale);
            return RCopy;
        }

        public static Rect operator /(Rect R, double scale)
        {
            return R * (1 / scale);
        }

        public override string ToString()
        {
            return LeftTop.ToString() + ", " + RightTop.ToString() + ", " + RightBottom.ToString() + ", " + LeftBottom.ToString();
        }
    }
}

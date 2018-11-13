using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB5_P
{
    class MyArray
    {
        private int[] arr;

        public int F1 { get; private set; }
        public int L1 { get; private set; }
        public int L2 { get; private set; }

        public MyArray(int[] arr, int f1, int l1, int l2)
        {
            this.arr = new int[arr.Length];
            Array.Copy(arr, this.arr, arr.Length);
            F1 = f1;
            L1 = l1;
            L2 = l2;
        }

        private void MainMerge(int[] numbers, int left, int mid, int right)
        {
            int[] temp = new int[numbers.Length];
            int i, eol, num, pos;

            eol = (mid - 1);
            pos = left;
            num = (right - left + 1);

            while ((left <= eol) && (mid <= right))
            {
                if (numbers[left] <= numbers[mid])
                    temp[pos++] = numbers[left++];
                else
                    temp[pos++] = numbers[mid++];
            }

            while (left <= eol)
                temp[pos++] = numbers[left++];

            while (mid <= right)
                temp[pos++] = numbers[mid++];

            for (i = 0; i < num; i++)
            {
                numbers[right] = temp[right];
                right--;
            }
        }

        private void SortMerge(int left, int right)
        {
            int mid;
            if (right > left)
            {
                mid = (right + left) / 2;
                SortMerge(left, mid);
                SortMerge(mid + 1, right);
                MainMerge(arr, left, mid + 1, right);
            }
        }

        public void SortMerge()
        {
            SortMerge(F1, L2);
        }

        public override string ToString()
        {
            return String.Join(", ", arr);
            
        }
    }
}

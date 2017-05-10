using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bài_2___Biến
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            /* string name, xepLoai;
             double diem;
             Console.WriteLine("Nhập Điểm: ");diem = double.Parse(Console.ReadLine());

             xepLoai = (diem >= 8.0 && diem <= 10.0) ? "Giỏi" : (diem >= 6.5 && diem < 8.0) ? "Khá" : (diem >= 5.0 && diem < 6.5) ? "Trung Bình" : "Yếu";

             Console.WriteLine("Ket qua: {0}", xepLoai);*/
            int thang, ngay = 0, nam = 0;
            Console.WriteLine("Nhập Tháng: "); thang = int.Parse(Console.ReadLine());
            if(thang != 2)
            {
                switch(thang)
                {
                    case 1: ngay = 31;break;
                    case 3: ngay = 31;break;
                    case 4: ngay = 30; break;
                    case 5: ngay = 31; break;
                    case 6: ngay = 30; break;
                    case 7: ngay = 31; break;
                    case 8: ngay = 31; break;
                    case 9: ngay = 30; break;
                    case 10: ngay = 31; break;
                    case 11: ngay = 30; break;
                    case 12: ngay = 31; break;
                }
                Console.WriteLine("Tháng {0} có {1} ngày.",thang,ngay);
            }
            else
            {
                Console.WriteLine("Nhập Năm: "); nam = int.Parse(Console.ReadLine());
                ngay = (nam % 4 == 0) ? 29 : 28;
                Console.WriteLine("Tháng {0} năm {1} có {2} ngày.",thang,nam,ngay);
            }
            Console.ReadLine();
        }
    }
}

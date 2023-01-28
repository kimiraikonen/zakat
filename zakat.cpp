#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Zakat {
public:
int vartinggalsholat,varakhirtinggal,hargaemas,bablas,qodho,harian;
double uang;

    void sholat()
    {
        ulang2:
        cout << "Dari Tahun Berapa Anda meninggalkan sholat? ";
        cin >> vartinggalsholat;

        if (cin.fail())
        {
            cout <<"Masukkan angka bukan huruf" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto ulang2;
        }

        cout << "Sampai Tahun Berapa?";
        cin >> varakhirtinggal;

        if (cin.fail())
        {
            cout <<"Masukkan angka bukan huruf" << endl;


            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto ulang2;
        }

        else if (vartinggalsholat > varakhirtinggal)
        {
            cout << "Yang betul lah ngisinya"<< endl;
            goto ulang2;
        }

        bablas=varakhirtinggal-vartinggalsholat;
        qodho=bablas*(360*5);
        harian=bablas*360;
        cout<<"ANDA MENINGGALKAN SHOLAT SELAMA "<<bablas<<" Tahun"<<endl;
        cout<<"SEHINGGA ANDA HARUS MENGGANTI SHOLAT SEBANYAK "<< qodho<< " waktu"<<endl;
        cout<<"Dengan Rincian : " <<endl;
        cout<<"Sholat Maghrib :"<<harian<<endl;
        cout<<"Sholat Isya:"<<harian<<endl;
        cout<<"Sholat Subuh :"<<harian<<endl;
        cout<<"Sholat Zuhur:"<<harian<<endl;
        cout<<"Sholat Ashar :"<<harian<<endl;


    }

    void bayarzakat()
    {
        ulang:
        cout << "Masukkan nominal uang anda yang tersimpang sekarang :";
        cin >> uang;

        if (cin.fail())
        {
            cout <<"Masukkan angka bukan huruf" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto ulang;
        }

        cout << "Masukan harga emas pergram saat ini  :";
        cin >> hargaemas;
        if (cin.fail())
        {
            cout <<"Masukkan angka bukan huruf" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto ulang;
        }



        if (uang> senilaiemas(hargaemas))
        {

            cout<<"ANDA WAJIB MEMBAYAR ZAKAT SEBANYAK Rp. "<<wajibzakat(uang)<<endl;
        }

        else
        {
            cout << "ANDA BELUM WAJIB ZAKAT"<<endl;
        }



    }

    void garis() {
        cout << "------------------------------------------------------" << endl;
    }

    int senilaiemas(double e) {
        return 85 * e;
    }

    int wajibzakat(double w) {
        return 0.025 * w;
    }
};

    int main() {
        int a,b;
        string kondisi,pilihan;

        //buat objekbaru namanya objekku
        Zakat objekku;

        while (true) {

            cout << "Aplikasi Penghitung Kewajiban Beribadah" << endl;
            cout << "              MY DUTY V 0.1     1       " << endl;
            objekku.garis();
            cout << "1. Zakat " << endl;
            cout << "2. Sholat " << endl;
            cout << "3. Quit " << endl;
            objekku.garis();

            cout << "Masukkan Pilihan anda : ";
            cin >> pilihan;

            if (pilihan == "1")
            {
                objekku.bayarzakat();
            }
            else if (pilihan=="2")
            {
                objekku.sholat();
            }
            else if (pilihan=="3")
            {
                exit(0);
            }
            else
            {
                cout<<"masukkan angka pilihan yang benar"<< endl;
            }


            objekku.garis();


            cout << "apakah anda mau hitung lagi? (y/n) : ";
            cin >> kondisi;

            objekku.garis();

            if (kondisi == "n") {
                break;
            }

        }


    }

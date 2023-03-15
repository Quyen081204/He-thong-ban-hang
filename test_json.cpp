#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "Class_Date.cpp"
#include "single_include/nlohmann/json.hpp"


using namespace std;
using json = nlohmann::json;


// Helper functions
namespace helper_functions {

    void error(string s)
    {
        cout << s << endl;
    }

    void skip_to_an_int()
    {
        if (cin.fail()) {
            cin.clear();

            for (char c;cin >> c;) {
                if (isdigit(c) || c == '-') {
                    cin.unget();
                    return;
                }
            }
        }
        else {
            cin.clear(ios_base::failbit);
            error("Invalid integer");
        }
    }

    int get_int()
    {
        int x = 0;
        while (true) {
            if (cin >> x) break;
            skip_to_an_int();
        }
        return x;
    }

    string get_string()
    {
        string s;
        while (true) {
            if (cin >> s) break;
            else {
                error("Invalid string");
                cin.clear();
            }
        }
        return s;
    }

}


// Requirement Start coding base class such as Smartphone, Macbook

namespace Smartphone {
	class VND
	{
	public:
		VND(int gia) {
			gia_ca = gia;
			VND_sign = '$';
		}
		VND() {
			gia_ca = 0;
			VND_sign = '$';
		}
		int get_price()const { return gia_ca; }
		char get_sign()const { return VND_sign; }

	private:
		int gia_ca;
		char VND_sign;
	};

	ostream& operator<< (ostream& os, const VND& price)
	{
		return os << price.get_price() << ' ' << price.get_sign();
	}

	//----------------------------------------------------------------------------------------------------------------------------------
	// Abstract class

	class Smartphone
	{
	public:
		virtual void mieu_ta_san_pham() = 0;  //===> abstract class
		Smartphone(string ten, string RAM, string dung_luong, string cam_truoc, string cam_sau, string pin, VND gia_ca);
		Smartphone() = default; // Default constructor
		virtual string get_name()const = 0;
		virtual string get_RAM()const = 0;
		virtual string get_storage()const = 0;
		virtual string get_camera_truoc()const = 0;
		virtual string get_camera_sau()const = 0;
		virtual string get_pin()const = 0;
		virtual VND get_price()const = 0;

	protected:
		string name;
		string RAM;
		string storage;
		string camera_truoc;
		string camera_sau;
		string Pin;
		VND price;
	};

	Smartphone::Smartphone(string ten, string Ram, string dung_luong, string cam_truoc, string cam_sau, string pin, VND gia_ca)
	{
		name = ten;
		RAM = Ram;
		storage = dung_luong;
		camera_truoc = cam_truoc;
		camera_sau = cam_sau;
		Pin = pin;
		price = gia_ca;
	}

	//----------------------------------------------------------------------------------------------------------------------------------

	class Iphone : public Smartphone
	{
	public:
		void mieu_ta_san_pham();
		string get_name()const;
		string get_RAM()const;
		string get_storage()const;
		string get_camera_truoc()const;
		string get_camera_sau()const;
		string get_pin()const;
		VND get_price()const;
		Iphone() { ma_dong_san_pham = "IP"; }  // call default constructor of Smartphone

	protected:
		string ma_dong_san_pham;
	};

	//----------------------------------------------------------------------------------------------------------------------------------

	string Iphone::get_name()const { return name; }
	string Iphone::get_RAM()const { return RAM; }
	string Iphone::get_storage()const { return storage; }
	string Iphone::get_camera_truoc()const { return camera_truoc; }
	string Iphone::get_camera_sau()const { return camera_sau; }
	string Iphone::get_pin()const { return Pin; }
	VND Iphone::get_price()const { return price; }

	//----------------------------------------------------------------------------------------------------------------------------------

	void Iphone::mieu_ta_san_pham()
	{
		cout << "\t\t" << name << endl
			<< "Ma dong san pham: " << ma_dong_san_pham << endl
			<< "RAM: " << RAM << endl
			<< "Dung luong: " << storage << endl
			<< "Camera truoc: " << camera_truoc << endl
			<< "Camera sau: " << camera_sau << endl
			<< "Pin: " << Pin << endl
			<< "Gia: " << price << endl;
	}

	//----------------------------------------------------------------------------------------------------------------------------------

	class Iphone12 : public Iphone
	{
	public:
		Iphone12();
		Iphone12(const json& j);
		json to_json() const;
	};


	// Constructor
	// Make a class from json
	Iphone12::Iphone12(const json& j)
	{
		/*for (auto& ip12 : j["Iphone"]) {

		}*/
		//json j = j2["Iphone"];
		name = j["name"].get<std::string>();
		RAM = j["RAM"].get<std::string>();
		storage = j["Storage"].get<std::string>();
		camera_truoc = j["Camera_truoc"].get<std::string>();
		camera_sau = j["Camera_sau"].get<std::string>();
		Pin = j["Pin"].get<std::string>();
		price = j["Price"].get<int>();
	}


	// Convert class to json
	
	json Iphone12::to_json()const
	{
		json object_ip12;
		object_ip12["name"] = name;
		object_ip12["RAM"] = RAM;
		object_ip12["Storage"] = storage;
		object_ip12["Camera_truoc"] = camera_truoc;
		object_ip12["Camera_sau"] = camera_sau;
		object_ip12["Pin"] = Pin;
		object_ip12["Price"] = price.get_price();
        return object_ip12;
	}


	// Default constructor
	Iphone12::Iphone12()
	{
		// Base depend on is's base class
		name = "Iphone12";
		RAM = "4 GB";
		storage = "64 GB";
		camera_sau = "2 camera 12 MP";
		camera_truoc = "12 MP";
		Pin = "2815 mAh";
		price = 16500000;
	}



	class Iphone13 : public Iphone
	{
	public:
		Iphone13();
		Iphone13(const json& j);
		json to_json()const;
	};


	// Constructor
	// Make a class from json
	Iphone13::Iphone13(const json& j)
	{
		/*for (auto& ip12 : j["Iphone"]) {

		}*/
		//json j = j2["Iphone"];
		name = j["name"].get<std::string>();
		RAM = j["RAM"].get<std::string>();
		storage = j["Storage"].get<std::string>();
		camera_truoc = j["Camera_truoc"].get<std::string>();
		camera_sau = j["Camera_sau"].get<std::string>();
		Pin = j["Pin"].get<std::string>();
		price = j["Price"].get<int>();
	}

	// Default constructor
	Iphone13::Iphone13()
	{
		// Base depend on is's base class
		name = "Iphone13";
		RAM = "4 GB";
		storage = "64 GB";
		camera_sau = "2 camera 12 MP";
		camera_truoc = "12 MP";
		Pin = "2815 mAh";
		price = 16500000;
	}


    // Convert class to json

    json Iphone13::to_json()const
    {
        json object_ip13;
        object_ip13["name"] = name;
        object_ip13["RAM"] = RAM;
        object_ip13["Storage"] = storage;
        object_ip13["Camera_truoc"] = camera_truoc;
        object_ip13["Camera_sau"] = camera_sau;
        object_ip13["Pin"] = Pin;
        object_ip13["Price"] = price.get_price();
        return object_ip13;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------

namespace STORE {

    const int MAX_ROW = 10;
    const int MAX_CLOUMN = 10;

    class SKU {
    public:
        SKU();
        SKU(int sku);
        void make_sku();
        int get_ma_sku()const { return ma_sku; }

    private:
        int mac_dinh = 23;
        int ma_sku;
    };

    SKU::SKU(int sku)  // tim san pham
    {
        ma_sku = sku;
    }

    SKU::SKU()
    {
        ma_sku = 0;
    }

    void SKU::make_sku()
    {
        // srand(time(NULL));
        for (int i = 0;i < 7;i++) {
            mac_dinh = mac_dinh * 10 + (rand() % (9 - 0 + 1) + 0);
        }
        ma_sku = mac_dinh;
        mac_dinh = 23;
    }

    ostream& operator<< (ostream& os, const SKU& sku)
    {
        return os << sku.get_ma_sku();
    }

    istream& operator>> (istream& is, SKU& sku)
    {
        int temp = helper_functions::get_int();
        sku = SKU(temp);
        return is;
    }

    bool operator==(const SKU& a, const SKU& b)
    {
        return a.get_ma_sku() == b.get_ma_sku();
    }


    bool operator!=(const SKU& a, const SKU& b)
    {
        return !(a == b);
    }
    //----------------------------------------------------------------------------------------------------------------------------------

    class Store_Iphone12 {
    public:
        // Store_Iphone12();
        void change_sku();    // thay doi ma sku
		void set_default();    // ma sku quay ve mac dinh
        Smartphone::Iphone12 get_ip12()const;
        SKU get_sku()const { return sku_ip12; }
        json to_json();

    private:
        Smartphone::Iphone12 ip12;
        SKU sku_ip12;
    };

    void Store_Iphone12::change_sku()
    {
        sku_ip12.make_sku();
    }


	void Store_Iphone12::set_default()
	{
		sku_ip12 = SKU(0);   // 
	}

    Smartphone::Iphone12 Store_Iphone12::get_ip12()const
    {
        return ip12;
    }


    json Store_Iphone12::to_json()
    {
        json j;
        j["name"] = ip12.get_name();
        j["RAM"] = ip12.get_RAM();
        j["Storage"] = ip12.get_storage();
        j["Camera_truoc"] = ip12.get_camera_truoc();
        j["Camera_sau"] = ip12.get_camera_sau();
        j["Pin"] = ip12.get_pin();
        j["Price"] = ip12.get_price().get_price();
        j["SKU"] = sku_ip12.get_ma_sku();
        return j;
    }
    //----------------------------------------------------------------------------------------------------------------------------------

    class Store_Iphone13 {
    public:
        void change_sku();
		void set_default();    // ma sku quay ve mac dinh
        Smartphone::Iphone13 get_ip13()const;
        SKU get_sku()const { return sku_ip13; }
        json to_json();
    private:
        Smartphone::Iphone13 ip13;
        SKU sku_ip13;
    };

    void Store_Iphone13::change_sku()
    {
        sku_ip13.make_sku();
    }

	void Store_Iphone13::set_default()
	{
		sku_ip13 = SKU(0);   // 
	}

    Smartphone::Iphone13 Store_Iphone13::get_ip13()const
    {
        return ip13;
    }

    json Store_Iphone13::to_json()
    {
        json j;
        j["name"] = ip13.get_name();
        j["RAM"] = ip13.get_RAM();
        j["Storage"] = ip13.get_storage();
        j["Camera_truoc"] = ip13.get_camera_truoc();
        j["Camera_sau"] = ip13.get_camera_sau();
        j["Pin"] = ip13.get_pin();
        j["Price"] = ip13.get_price().get_price();
        j["SKU"] = sku_ip13.get_ma_sku();
        return j;
    }

    //----------------------------------------------------------------------------------------------------------------------------------

    class Store_Iphone {
    public:
        void nhap_ip12();
        void nhap_ip13();
        void xuat_file_store_iphone();   // json
		void xuat_file_lich_su(string date);
		bool tim_san_pham(const SKU& check_sku);
		bool xoa_san_pham(const SKU& check_sku);

        Store_Iphone12* tim_Iphone12(const SKU& check_sku);
        Store_Iphone13* tim_Iphone13(const SKU& check_sku);
    
		Store_Iphone12* get_not_ip12()const { return ptr_not_a_ip12; }
		Store_Iphone13* get_not_ip13()const { return ptr_not_a_ip13; }
		Store_Iphone12* get_ptr_keeptrack_ip12()const { return ptr_keep_track_ip12; }
		Store_Iphone13* get_ptr_keeptrack_ip13()const { return ptr_keep_track_ip13; }

    private:
		json history;
		json xoa_ip12 = json::array();
		json xoa_ip13 = json::array();
        json store_iphone;
        json Jstr_ip12 = json::array();   // push back str_ip12 for store ip12 and sku
        json Jstr_ip13 = json::array();   // push back str_ip12 for store ip12 and sku

        Store_Iphone12* ptr_not_a_ip12 = nullptr;    // neu khong tim thay
        Store_Iphone13* ptr_not_a_ip13 = nullptr;    // neu khong tim thay
          Store_Iphone12* ptr_keep_track_ip12 = 0;
          Store_Iphone13* ptr_keep_track_ip13 = 0;

        Store_Iphone12 store_ip12[MAX_ROW][MAX_CLOUMN];   // chua duoc 100 cai
        Store_Iphone13 store_ip13[MAX_ROW][MAX_CLOUMN];
        vector<SKU> all_sku;

        string file_output_name = "StoreIphone.json";
		string file_lich_su = "History.json";
    };

    void Store_Iphone::nhap_ip12()
    {
       
        if (ptr_keep_track_ip12 != 0 && ptr_keep_track_ip12 != &(store_ip12[MAX_ROW-1][MAX_CLOUMN-1])) {
            bool is_exist = true;
            while (is_exist) {
                (ptr_keep_track_ip12 + 1)->change_sku();
                // Check whether sku is exist already
                for (int i = 0;i < all_sku.size();i++) 
                {
                    if ((ptr_keep_track_ip12 + 1)->get_sku() == all_sku[i]) {
                        is_exist = true;
                        break;
                    }
                    else {
                        is_exist = false;
                    }
                }
              }

            all_sku.push_back((ptr_keep_track_ip12 + 1)->get_sku());     // Add SKU
            Jstr_ip12.push_back((ptr_keep_track_ip12 + 1)->to_json());   // ADD IPHONE12 TO json arr
            ptr_keep_track_ip12++;    // Keep track the last iphone putback
        }
        else if (ptr_keep_track_ip12 == &(store_ip12[MAX_ROW - 1][MAX_CLOUMN - 1])) {
            error("Sorry, we can't store anymore");
            return;
        }   // last address
        else {
            store_ip12[0][0].change_sku();
            Jstr_ip12.push_back(store_ip12[0][0].to_json());
            all_sku.push_back(store_ip12[0][0].get_sku());
            ptr_keep_track_ip12 = &(store_ip12[0][0]);
        }
    }

    void Store_Iphone::nhap_ip13()
    {
        if (ptr_keep_track_ip13 != 0 && ptr_keep_track_ip13 != &(store_ip13[MAX_ROW-1][MAX_CLOUMN-1])) {
            bool is_exist = true;
            while (is_exist) {
                (ptr_keep_track_ip13 + 1)->change_sku();
                // Check whether sku is exist already
                for (int i = 0;i < all_sku.size();i++) 
                {
                    if ((ptr_keep_track_ip13 + 1)->get_sku() == all_sku[i]) {
                        is_exist = true;
                        break;
                    }
                    else {
                        is_exist = false;
                    }
                }
            }

            all_sku.push_back((ptr_keep_track_ip13 + 1)->get_sku());
            Jstr_ip13.push_back((ptr_keep_track_ip13 + 1)->to_json());   // ADD iphone13 to json arr; 
            ptr_keep_track_ip13++;   // Keep track the last iphone putback
        }
        else if (ptr_keep_track_ip13 == &(store_ip13[MAX_ROW - 1][MAX_CLOUMN - 1])) {
            error("Sorry, we can't store anymore");
            return;   // last address
        }
        else {
            store_ip13[0][0].change_sku();
            Jstr_ip13.push_back(store_ip13[0][0].to_json());
            ptr_keep_track_ip13 = &(store_ip13[0][0]);
        }

    }

    /* 
        Xuat file de lay ma dinh danh
    */
    void Store_Iphone::xuat_file_store_iphone()    
    {
        ofstream ost{ file_output_name };
        if (!ost) helper_functions::error("Can't open file");
        cout << "Kho thong tin iphone luu tru o file: " << file_output_name << endl;    
              /*  store_iphone["Iphone12"] = Jstr_ip12;
                store_iphone["Iphone13"] = Jstr_ip13;*/
		json j_ip12 = json::array();
		json j_ip13 = json::array();

		// Lap trong store_ip12
		for (Store_Iphone12* ptr = &(store_ip12[0][0]);ptr <= ptr_keep_track_ip12; ptr++)
		{
			j_ip12.push_back(ptr->to_json());   // Convert to json 
		}

		// Lap trong store_ip13
		for (Store_Iphone13* ptr = &(store_ip13[0][0]);ptr <= ptr_keep_track_ip13; ptr++)
		{
			j_ip13.push_back(ptr->to_json());   // Convert to json 
		}

		store_iphone["File"] = "KHO HANG IPHONE";
		store_iphone["Iphone12"] = j_ip12;
		store_iphone["Iphone13"] = j_ip13;

        ost << store_iphone.dump(1, '\t');
        cout << "Xuat file thanh cong" << endl;
        return;
    }


	void Store_Iphone::xuat_file_lich_su(string date)
	{
		ofstream ost{ file_lich_su };
		cout << "Lich su giao dich luu tru o file: " << file_lich_su << endl;

		history["File"] = "LICH SU GIAO DICH";
		history["Date"] = date;
		history["Iphone12"] = xoa_ip12;
		history["Iphone13"] = xoa_ip13;

		ost << history.dump(4);
		cout << "Xuat file lich su thanh cong" << endl;
		return;
	}


    // Tim san pham

    Store_Iphone12* Store_Iphone::tim_Iphone12(const SKU& check_sku)
    {
        int* ptr = new int;
        *ptr = 0;
        // Neu chua nhap hang --> thoat
        if (store_ip12[0][0].get_sku().get_ma_sku() == *ptr) {
            delete ptr;
            return ptr_not_a_ip12;
        }
        else {
            delete ptr;
        }
        for (Store_Iphone12* ptr_ip12 = &(store_ip12[0][0]); ptr_ip12 <= ptr_keep_track_ip12; ++ptr_ip12) {
            if (check_sku == ptr_ip12->get_sku()) {
                return ptr_ip12;   // tra ve dia chi noi chua dung ma dinh danh
            }
        }
        return ptr_not_a_ip12;
    }


    Store_Iphone13* Store_Iphone::tim_Iphone13(const SKU& check_sku)
    {
        int* ptr = new int;
        *ptr = 0;
        // Neu chua nhap hang --> thoat
        if (store_ip13[0][0].get_sku().get_ma_sku() == *ptr) {
            delete ptr;
            return ptr_not_a_ip13;
        }
        else {
            delete ptr;
        }
        for (Store_Iphone13* ptr_ip13 = &(store_ip13[0][0]); ptr_ip13 <= ptr_keep_track_ip13; ++ptr_ip13) {
            if (check_sku == ptr_ip13->get_sku()) {
                return ptr_ip13;   // tra ve dia chi noi chua dung ma dinh danh
            }
        }
        return ptr_not_a_ip13;
    }


    bool Store_Iphone::tim_san_pham(const SKU& check_sku)
    {
        // Kiem tra trong kho Iphone12
        if (&(store_ip12[0][0]) <= tim_Iphone12(check_sku) && tim_Iphone12(check_sku) <= ptr_keep_track_ip12) {
                tim_Iphone12(check_sku)->get_ip12().mieu_ta_san_pham();
                cout << "SKU: " << tim_Iphone12(check_sku)->get_sku() << endl;
            return true;
        } 

        // Kiem tra trong kho Iphone13
        if (&(store_ip13[0][0]) <= tim_Iphone13(check_sku) && tim_Iphone13(check_sku) <= ptr_keep_track_ip13) {
                tim_Iphone13(check_sku)->get_ip13().mieu_ta_san_pham();
                cout << "SKU: " << tim_Iphone13(check_sku)->get_sku() << endl;
            return true;
        }

        // Neu tim ko thay
        return false;
    }


	bool Store_Iphone::xoa_san_pham(const SKU& check_sku)
	{
		if (tim_Iphone12(check_sku) != ptr_not_a_ip12)
		{
			// Xoa san pham
			xoa_ip12.push_back(tim_Iphone12(check_sku)->to_json());
			//tim_Iphone12(check_sku)->set_default();   // Thay doi ma dinh danh ve mac dinh
			*(tim_Iphone12(check_sku)) = *ptr_keep_track_ip12;  // doi cho thang xoa voi thang cuoi cung keep track
			ptr_keep_track_ip12->set_default();
			ptr_keep_track_ip12--;

            // Xoa trong vector SKU
            
            for (int i = 0;i < all_sku.size();i++)
            {
                if (all_sku[i] == check_sku)
                {
                    all_sku[i] = SKU(0);    // Set default
                    break;
                }
            }
			return true;
		}

		if (tim_Iphone13(check_sku) != ptr_not_a_ip13)
		{
			// Xoa san pham
			xoa_ip13.push_back(tim_Iphone13(check_sku)->to_json());
			//tim_Iphone13(check_sku)->set_default();   // Thay doi ma dinh danh ve mac dinh
			*(tim_Iphone13(check_sku)) = *ptr_keep_track_ip13;  // doi cho thang xoa voi thang cuoi cung keep track
			ptr_keep_track_ip13->set_default();
			ptr_keep_track_ip13--;

            // Xoa trong vector SKU

            for (int i = 0;i < all_sku.size();i++)
            {
                if (all_sku[i] == check_sku)
                {
                    all_sku[i] = SKU(0);    // Set default
                    break;
                }
            }
			return true;
		}

		return false;
		
	}

    //    //----------------------------------------------------------------------------------------------------------------------------------
    
    void help();
  
    class Store {
    public:
        void nhap_hang_qua_json();     // Done nhap hang
        void nhap_bang_tay();         // ---> tao ra 1 file json r doc 
        bool tim_san_pham(); 
        void nhap_ngay();
        //void xuat_hang();            //-- > su dung dia chi
        bool xoa_san_pham();

    private:
        json j_nhap;           // file chua thong tin nhap hang
        json j_xuat;
        Date is_valid_date;
        string today;
        string file_nhap = "nhap_Hang.json";
        string file_xuat = "xuat_Hang.json";
        Store_Iphone just_iphone;
    };

        //----------------------------------------------------------------------------------------------------------------------------------


    void Store::nhap_ngay()
    {
        int* ptr = new int;
        *ptr = 10;
        string date;
        stringstream ss;   // can be treated as source of istream , it read from a string
      
        while (true) {
            cout << "Moi ban nhap ngay (EX: 10/03/2023): ";
            if (cin >> date) {
                if (date.size() == *ptr) {
                    ss.str(date);   // set string of ss to string date
                    ss >> is_valid_date;   // check string date
                    today = date;   // if check is sucessful
                    break;
                }
            }
            else {
                cin.clear();
            }
            
        }

        delete ptr;
    }

    //----------------------------------------------------------------------------------------------------------------------------------


    void Store::nhap_bang_tay()
    {
        ofstream ost{ file_nhap };   // Open file for writting
        string ma_dong_sp;
        string ten_model;
        int so_luong = 0;
        json j_Iphone = json::array();

        help();   // Danh cho menu
        nhap_ngay();   // Nhap ngay
        cout << endl;
        j_nhap["Date"] = today;
        // co them them macbook vao
            cout << "Moi ban nhap ma dong san pham: ";
            ma_dong_sp = helper_functions::get_string();

            if (ma_dong_sp == "Iphone") {
                bool next = true;
                while (next)
                {
                    cout << "Moi ban nhap ten models (Iphone12 hoac Iphone13) : ";
                    ten_model = helper_functions::get_string();
                    cout << endl;

                    if (ten_model == "Iphone12")
                    {
                        Smartphone::Iphone12* ip12 = new Smartphone::Iphone12();
                        cout << "Moi ban nhap so luong: ";
                        so_luong = helper_functions::get_int();
                        // Nhap vao json

                        for (int i = 0;i < so_luong;i++)
                        {
                            j_Iphone.push_back(ip12->to_json());
                        }
                        delete ip12;

                    }
                    else if (ten_model == "Iphone13")
                    {
                        Smartphone::Iphone13* ip13 = new Smartphone::Iphone13();
                        cout << "Moi ban nhap so luong: ";
                        so_luong = helper_functions::get_int();
                        // Nhap vao json

                        for (int i = 0;i < so_luong;i++)
                        {
                            j_Iphone.push_back(ip13->to_json());
                        }
                        delete ip13;
                    }
                    else if (ten_model == "1")
                    {
                        help();
                    }
                    else if (ten_model == "EXIT")
                    {
                        next = false;
                    }
                    else {
                        error("Chung toi Khong nhap mat hang nay, vui long thu lai");
                        cout << endl;
                    }
                }
            }
        j_nhap["Iphone"] = j_Iphone;

        //j_nhap["Macbook"] = j_macbook;

        ost << j_nhap.dump(5);    // Xuat file;
        cout << "Thong tin ve hang nhap o file: " << file_nhap << endl;

        // Nhap hang vo kho hang

        nhap_hang_qua_json();

        return;
    }

    //----------------------------------------------------------------------------------------------------------------------------------

    void Store::nhap_hang_qua_json()
    {
        if (j_nhap.contains("Iphone")) {
            for (json::iterator it = j_nhap["Iphone"].begin(); it != j_nhap["Iphone"].end(); ++it) {
                json j = *it;
                if (j["name"] == "Iphone12") {
                    just_iphone.nhap_ip12();
                }
                else if (j["name"] == "Iphone13") {
                    just_iphone.nhap_ip13();
                }
            }
            just_iphone.xuat_file_store_iphone();   // xuat file chua thong tin hang da nhap
        }
    }

    //----------------------------------------------------------------------------------------------------------------------------------

    bool Store::tim_san_pham()
    {
        SKU check_sku;
        cout << "Tim kiem san pham moi ban nhap ma dinh danh (SKU trong file StoreIphone.json): ";
        cin >> check_sku;
        if (just_iphone.tim_san_pham(check_sku)) {
            return true;
        }
        // Macbook.tim_san_pham(check_sku)
        return false;
    }

    //----------------------------------------------------------------------------------------------------------------------------------

    //void Store::xuat_hang()
    //{
    //    // Xoa ma dinh danh trong vector SKU
    //    // Xoa trong mang 
    //    ofstream ost{ file_xuat };   // Open file for writting
    //    string ma_dong_sp;
    //    string ten_model;
    //    int so_luong = 0;
    //    json j_Iphone = json::array();
    //    help();   // Danh cho menu
    //    nhap_ngay();   // Nhap ngay
    //    cout << endl;
    //    j_nhap["Date"] = today;

    //    cout << "Moi ban nhap ma dong san pham: ";
    //    ma_dong_sp = helper_functions::get_string();

    //   
    //}


    bool Store::xoa_san_pham()
    {
		nhap_ngay();
        SKU check_sku;
        cout << "Xoa san pham moi ban nhap ma dinh danh (SKU trong file): ";
        cin >> check_sku;

		if (just_iphone.xoa_san_pham(check_sku)) 
		{
			just_iphone.xuat_file_lich_su(today);
			just_iphone.xuat_file_store_iphone();
			return true;
		} 
		return false; 
    }

    void help()
    {
        cout << "\t\t\t READ ME" << endl << endl;
        cout << "- Chung toi chi luu tru dong dien thoai la Iphone12 va Iphone13 , ma dong san pham Iphone." << endl << endl
            << "- Khi nhap hang xong de thoat ban vui long go EXIT khi nhap ten model." << endl << endl
            << "- Tim kiem san pham ban nhap ma SKU trong file (StoreIphone.json)." << endl << endl
            << "- GOI HO TRO BAM PHIM 1, xin cam on." << endl << endl;
    }
}

int main()
try
{
    srand(time(NULL));


	STORE::Store* myStore = new STORE::Store();   // moving data to heap
	myStore->nhap_bang_tay();
	if (myStore->tim_san_pham()) {
		cout << "Tim thanh cong" << endl;
	}
	else cout << "Khong tim thay ma trong kho cua chung toi" << endl;
	myStore->xoa_san_pham();
	delete myStore;


	/* 
		- Done xoa xong 1 san pham bang ma dinh danh
		- Con xoa nhieu san pham 1 luc 
	*/












	






    // Thanh cong

    // Tomorrow done - xuat hang 
    //               - Nhap bang tay


 






  

	std::system("pause");
	return 0;
}
catch (Date::Invalid)
{
    error("Invalid date");
}
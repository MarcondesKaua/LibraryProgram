#include <iostream>
#include <string>
#include <list>

 
struct Date {

	std::string day;
	std::string month;
	std::string year;
	

	void show_date() {
	std::cout << day << "/" << month << "/" << year;
	

	}

	bool valid_date() {
		try {

		int d = std::stoi(day);
		int m = std::stoi(month);
		int y = std::stoi(year);

		int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if(y % 4 == 0 && y %100 != 0 || y %400 == 0) {
			days_in_months[1] = 29;
		}

		if (m>= 1 && m <= 12) {
			if (d <= days_in_months[m -1 ] && d >= 1) {
				return true;
			}
		}


		}
		catch (...) {
		return false;

		}
			
		
		return false;
	};

	void fill_date() {
	std::string input_controller;


	
	while (true) {
	std::cout << "Forneca sua data de nascimento (DD/MM/AAAA): ";
	std::getline(std::cin >> std::ws, input_controller);

	if (input_controller.length() >= 10 && input_controller[2] == '/' && input_controller[5] == '/') {
	
		day = input_controller.substr(0, 2);
		month = input_controller.substr(3, 2);
		year = input_controller.substr(6, 4);
	
	if (valid_date()) {
		break;
	}
	
	} 
	std::cout << "Formato invalido, tente novamente. (Ex: 01/01/2000)" << std::endl;
	}

	}

};

struct Student { 

	std::string name;
	std::string ra;
	int current_year;
	Date birth_date;



	void fill_student() {
	
	

		std::cout << "Digite seu nome ";
		std::getline(std::cin >> std::ws, name);

		std::cout << "Digite seu RA ";
		std::cin >> ra;

		std::cout << "Digite o ano em que esta ";
		std::cin >> current_year;
	

		birth_date.fill_date();

		
}

	
	void show_student() {

		std:: cout << "--------------------------------\n";
		std::cout << "Nome: " << name << "\nRA: " << ra << "\nAno atual: " << current_year << "\nData de nascimento: " ;
		birth_date.show_date();
		std:: cout << "\n--------------------------------" << "\n \n";
	}



	
};


struct Book {

	std::string title;
	std::string author;
	int year_published;
	int quantity_in_shelf;

	int id;

	void fill_book() {


		std::cout << "Digite o titulo do livro ";
		std::getline(std::cin >> std::ws, title);

		std::cout << "Digite o autor do livro ";
		std::getline(std::cin >> std::ws, author);

		std::cout << "Digite o ano de publicaçao ";
		std::cin >> year_published;

		std::cout << "Digite quantos exemplares estao disponiveis ";
		std::cin >> quantity_in_shelf;

		static int id_count = 3;
		this->id = id_count;
		id_count++;
	

	}


	void show_book() {
		std:: cout << "--------------------------------\n";
		std::cout << "Titulo: " << title << "\nAutor: " << author << "\nAno de publicacao: " << year_published << "\nQuantidade no acervo: " << quantity_in_shelf <<"\nID: " << this->id ;
		std:: cout << "\n--------------------------------" << "\n \n";
	
	}


};

void fill_book_to_list(std::list <Book>& book_list){
	Book temp;
	temp.fill_book();
	book_list.push_front(temp);

}

void fill_student_to_list(std::list <Student>& students_list) {
	Student temp;
	temp.fill_student();
	students_list.push_front(temp);
}


void delete_student(std::string ra_delete, std::list<Student>& students_list) {

		for (auto i = students_list.begin(); i != students_list.end();) {

			if (i -> ra == ra_delete) {
				i = students_list.erase(i);
			}
			else {
				i++;
			}

		}
		
	}

void delete_book (int id_delete, std::list <Book>& book_list) {
	

	
	for (auto i = book_list.begin(); i != book_list.end();) {
		
		if (i -> id == id_delete) {
			i= book_list.erase(i);

		} 
		else {
			i++;
		}
	}

}

/* void fill_student(std::list <Student>& students_list) {
	
	Student temp;

	std::cout << "Digite seu nome ";
	std::getline(std::cin >> std::ws, temp.name);

	std::cout << "Digite seu RA ";
	std::cin >> temp.ra;

	std::cout << "Digite o ano em que esta ";
	std::cin >> temp.current_year;
	

	temp.birth_date.fill_date();

	students_list.push_front(temp);
}
 */

int main() {

	std::list <Student> students_list {

		{"Kaua Marcondes dos Santos", "123456789", 3, {"06", "10", "2008"} },
		{"Santos dos Marcondes Kaua", "98765431", 3, {"10", "06", "2008"} }

	};
	
	std::list <Book> book_list {

		{"Senhor dos aneis", "J. R. R. Tolkien", 1949, 3, 1 },
		{"Tristan e Isolda", "Thomas da Bretanha", 1170, 2, 2}

	};
	int menu_answer;

	std::cout << "Menu de opcoes: " 
	<< "\n -----------------"
	<< "\n 1 Inserir alunos"
	<< "\n 2 Inserir livros"
	<< "\n 3 Deletar alunos"
	<< "\n 4 Deletar livros"
	<< "\n 5 Mostrar alunos"
	<< "\n 6 Mostrar livros"
	<< "\n 7 Sair do sistema \n" ;

	

	while (true) {

	std::cin >> menu_answer;	

	switch (menu_answer){
	case 1:
			fill_student_to_list(students_list);
		break;


		case 2:
			fill_book_to_list(book_list);
		break;


		case 3: {
			std::string temp_ra;
			std::cout << "Qual o RA do aluno que você quer apagar :";
			std::cin >> temp_ra;
			

			delete_student(temp_ra, students_list);
		break;
		}
		
		case 4: {
			int id_delete;
			std::cout << "Qual o ID do livro que voce quer apagar: ";
			std::cin >> id_delete;
			
			delete_book(id_delete, book_list);
		break;
		}
		case 5: 
			
			students_list.sort([](Student& n1, Student& n2){
			std::string n1_string = n1.name;
			std::string n2_string =n2.name;


			for (char& x : n1_string) {
			x = tolower(x);
			}

			for (char& x : n2_string) {
			x = tolower(x);
			}
			return n1_string < n2_string;


			});
			for (Student x : students_list) {
			x.show_student();
			}

		break;
		
		case 6:
			book_list.sort([](Book& n1, Book& n2) {
			std::string n1_string = n1.title;
			std::string n2_string = n2.title;

			for (char& x : n1_string) {
				x = tolower(x);
			}

			for (char& x : n2_string) {
				x = tolower(x);
			}

			return n1_string < n2_string;
		});


			for (Book x : book_list) {
				x.show_book();
			}
	
		break;

		case 7:
			exit(0);

		default: 
			std::cout << "Deu mole, ta digitando errado";
			break;
	}
	}
	
	return 0;

	}
	
	

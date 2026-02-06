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

	void fill_date() {
	std::string input_controller;
	
	while (true) {
	std::cout << "Forneca sua data de nascimento (DD/MM/AAAA): ";
	std::getline(std::cin >> std::ws, input_controller);

	if (input_controller.length() >= 10 && input_controller[2] == '/' && input_controller[5] == '/') {
	
	day = input_controller.substr(0, 2);
	month = input_controller.substr(3, 2);
	year = input_controller.substr(6, 4);

	break;
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

		std::cout << "Nome: " << name << "\nRA: " << ra << "\nAno atual: " << current_year << "\nData de nascimento: " ;
		birth_date.show_date();
		std::cout << std::endl;
	}
};


struct Book {

	std::string title;
	std::string author;
	int year_published;
	int quantity_in_shelf;

	void fill_book() {
		std::cout << "Digite o titulo do livro ";
		std::getline(std::cin >> std::ws, title);

		std::cout << "Digite o autor do livro ";
		std::cin >> author;

		std::cout << "Digite o ano de publicaçao ";
		std::cin >> year_published;

		std::cout << "Digite quantos exemplares extao disponiveis ";
		std::cin >> quantity_in_shelf;
	

	}


	void show_book() {

		std::cout << "Titulo: " << title << "\nAutor: " << author << "\nAno de publicaçao: " << year_published << "\nQuantidade no acervo: " << quantity_in_shelf ;
	
	}


};

void fill_student_to_list(std::list <Student>& students_list) {
	Student temp;
	temp.fill_student();
	students_list.push_front(temp);
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

		{"Senhor dos aneis", "J. R. R. Tolkien", 1949, 3 },
		{"Tristan e Isolda", "Thomas da Bretanha", 1170, 2}

	};

	fill_student_to_list(students_list);

	for (Student x : students_list) {
		x.show_student();
	}
	
	return 0;
}
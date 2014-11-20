#ifndef EBOOK_H
#define EBOOK_H

class eBook{
	std::string author;
	std::string title;

	int year;
	int total_pages;

	double cost;

	std::string text;

	public:
		eBook(std::string a, std::string t, int y, int tp, double c, std::string txt):
			author(a), title(t), year(y), total_pages(tp), cost(c), text(txt) {}

		// Setters
		void setAuthor(std::string a) { author = a; }
		void setTitle(std::string t) { title = t; }
		void setYear(int y) { year = y; }
		void setPages(int tp) { total_pages = tp; }
		void setText(std::string t) { text = t; }
		void setCost(double c) { cost = c; }

		// Getters 
		std::string getAuthor() { return author; }
		std::string getTitle() { return title; }
		int getYear() { return year; }
		int getTotalPages() { return total_pages; }
		std::string getText() { return text; }
		double getCost() { return cost; }
};

#endif
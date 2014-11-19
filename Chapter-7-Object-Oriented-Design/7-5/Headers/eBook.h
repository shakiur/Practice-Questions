#ifndef EBOOK_H
#define EBOOK_H

class eBook{
	std::string author;
	std::string title;

	int year;
	int total_pages;

	std::string text;

	public:
		eBook(std::string a, std::string t, int y, int tp):
			author(a), title(t), year(y), total_pages(tp) {}

		// Setters
		void setAuthor(std::string a) { author = a; }
		void setTitle(std::string t) { title = t; }
		void setYear(int y) { year = y; }
		void setPages(int tp) { total_pages = tp; }

		// Getters 
		std::string getAuthor() { return author; }
		std::string getTitle() { return title; }
		int getYear() { return year; }
		int getTotalPages() { return total_pages; }
};

#endif
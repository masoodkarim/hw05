class SmartString
{
private:
  int m_length;
  char* m_text;

  // ========== Internal methods.
  // Calculates length of text.
  int calculate_text_length(const char*);
  // Copies one char array to another.
  void copy_text(char* dest, const char* src);

public:
  // ========== -ctors.
  SmartString();
  ~SmartString();
  SmartString(const SmartString&);
  SmartString(const char*);

  // ========== Concatenation.
  void join(const SmartString&);
  void join(const char*);
  SmartString operator+(const SmartString&);
  SmartString operator+(const char*);

  // ========== Assigement.
  SmartString& operator=(const SmartString&);
  SmartString& operator=(const char*);

  // ========== Concatenation and Assigement.
  SmartString& operator += (const SmartString&);
  SmartString& operator += (const char*);

  // ========== Comparison.
  bool operator==(const SmartString&);
  bool operator==(const char*);

  // ========== Query.
  int length();
  void show();
};

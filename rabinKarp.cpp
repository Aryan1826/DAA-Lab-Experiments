Function RabinKarpSearch(Text, Pattern, Prime_Modulus, Base):
  n = Length(Text)
  m = Length(Pattern)

  // Calculate hash for the pattern
  Pattern_Hash = CalculateHash(Pattern, 0, m-1, Prime_Modulus, Base)

  // Calculate hash for the first window of text
  Text_Window_Hash = CalculateHash(Text, 0, m-1, Prime_Modulus, Base)

  // Precompute the highest power of Base for efficient rolling hash
  H = (Base ^ (m-1)) mod Prime_Modulus 

  Found_Indices = []

  For i from 0 to n - m:
    If Pattern_Hash == Text_Window_Hash:
      // If hashes match, perform a character-by-character comparison to confirm
      If Substring(Text, i, i+m-1) == Pattern:
        Add i to Found_Indices

    If i < n - m:
      // Calculate hash for the next window using rolling hash
      // Remove leading character's contribution
      Text_Window_Hash = (Text_Window_Hash - (Character_Value(Text[i]) * H)) mod Prime_Modulus
      
      // Handle potential negative hash values
      If Text_Window_Hash < 0:
        Text_Window_Hash = Text_Window_Hash + Prime_Modulus

      // Add trailing character's contribution
      Text_Window_Hash = (Text_Window_Hash * Base + Character_Value(Text[i+m])) mod Prime_Modulus

  Return Found_Indices


Function CalculateHash(String, Start_Index, End_Index, Prime_Modulus, Base):
  Hash_Value = 0
  For j from Start_Index to End_Index:
    Hash_Value = (Hash_Value * Base + Character_Value(String[j])) mod Prime_Modulus
  Return Hash_Value

Function Character_Value(Char):
  // Returns a numerical value for the character (e.g., ASCII value or a custom mapping)
  Return Ordinal_Value(Char) 
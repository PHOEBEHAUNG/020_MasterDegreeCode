//// 運算符號的位置為判斷
//https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
class Expression
{ 
  static class PStack
  {
    private char[] stack;
    private int index = -1;

    public PStack(int iMaxCount)
    {
      stack = new char[iMaxCount];
    }

    public void Reset()
    {
      index = -1;
    } 

    public int Push(char element)
    {
      if((index + 1) >= stack.length)
      {
        return -1;
      }

      index++;
      stack[index] = element;
      return 0;
    }

    public char Get()
    {
      if(index < 0)
      {
        return 'Q';
      }
      char res = stack[index];
      return res;
    }

    public char Pop()
    {
      if(index < 0)
      {
        return 'Q';
      }
      char res = stack[index];
      index--;
      return res;
    }

    public void Free()
    {
      stack = null;
    }
  }

  static boolean isOperator(char x)
  {
    switch (x) 
    {
      case '+':
      case '-':
      case '/':
      case '*':
      case '^':
      return true;
    }
    return false;
  }

  static int Prec(char ch) 
  { 
    switch (ch) 
    { 
      case '+': 
      case '-': 
        return 1; 
       
      case '*': 
      case '/': 
        return 2; 
       
      case '^': 
        return 3; 
    } 
    return -1; 
  }

/**
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty           
      or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. 
      After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
 */

  static String infixToPostfix(String exp)
  {
    PStack pStack = new PStack(exp.length());
    int i = 0;
    char c = 'A';
    String res = "";
    
    pStack.Reset();
    for(i = 0; i < exp.length(); i++)
    {
      if(!isOperator(exp.charAt(i)) && exp.charAt(i) != '(' && exp.charAt(i) != ')')
      {
        res = res + String.valueOf(exp.charAt(i));
        continue;
      }

      if(isOperator(exp.charAt(i)))
      {
        c = pStack.Get();
        /// 再思考
        while(Prec(c) >= Prec(exp.charAt(i)) && c != 'Q')
        {
          res = res + String.valueOf(pStack.Pop());
          c = pStack.Get();
        }
        pStack.Push(exp.charAt(i));
        continue;
      }

      if(exp.charAt(i) == '(')
      {
        pStack.Push(exp.charAt(i));
        continue;
      }

      if(exp.charAt(i) == ')')
      {
        c = pStack.Pop();
        while(c != '(')
        {
          res = res + String.valueOf(c);
          c = pStack.Pop();
        }
        continue;
      }
    }

    c = pStack.Pop();
    while(c != 'Q')
    {
      res = res + String.valueOf(c);
      c = pStack.Pop();
    }

    pStack.Free();
    return res;
  }

  static String infixToPrefix(String exp)
  {
    PStack pStack = new PStack(exp.length());
    int i = 0;
    char c = 'A';
    String revert = "";
    String res    = "";
    
    for(i = exp.length() - 1; i >= 0; i--)
    {
      c = exp.charAt(i);

      if(c == '(')
      {
        revert = revert + String.valueOf(')');
      }
      else if(c == ')')
      {
        revert = revert + String.valueOf('(');
      }
      else
      {
        revert = revert + String.valueOf(c);
      }
    }

    pStack.Reset();
    for(i = 0; i < revert.length(); i++)
    {
      if(!isOperator(revert.charAt(i)) && revert.charAt(i) != '(' && revert.charAt(i) != ')')
      {
        res = res + String.valueOf(revert.charAt(i));
        continue;
      }

      if(isOperator(revert.charAt(i)))
      {
        c = pStack.Get();
        /// 再思考
        while(Prec(c) >= Prec(revert.charAt(i)) && c != 'Q')
        {
          res = res + String.valueOf(pStack.Pop());
          c = pStack.Get();
        }
        pStack.Push(revert.charAt(i));
        continue;
      }

      if(revert.charAt(i) == '(')
      {
        pStack.Push(revert.charAt(i));
        continue;
      }

      if(revert.charAt(i) == ')')
      {
        c = pStack.Pop();
        while(c != '(')
        {
          res = res + String.valueOf(c);
          c = pStack.Pop();
        }
        continue;
      }
    }

    c = pStack.Pop();
    while(c != 'Q')
    {
      res = res + String.valueOf(c);
      c = pStack.Pop();
    }

    revert = "";
    for(i = res.length() - 1; i >= 0; i--)
    {
      c = res.charAt(i);
      revert = revert + String.valueOf(c);
    }

    pStack.Free();
    return revert;
  }

  /**
  https://www.geeksforgeeks.org/prefix-postfix-conversion/
  Algorithm for Prefix to Postfix: 

  Read the Prefix expression in reverse order (from right to left)
  If the symbol is an operand, then push it onto the Stack
  If the symbol is an operator, then pop two operands from the Stack 
  Create a string by concatenating the two operands and the operator after them. 
  string = operand1 + operand2 + operator 
  And push the resultant string back to Stack
  Repeat the above steps until end of Prefix expression.
   */

  /**
  https://www.geeksforgeeks.org/postfix-prefix-conversion/?ref=rp 
  Algorithm for Postfix to Prefix: 

  Read the Postfix expression from left to right
  If the symbol is an operand, then push it onto the Stack
  If the symbol is an operator, then pop two operands from the Stack 
  Create a string by concatenating the two operands and the operator before them. 
  string = operator + operand2 + operand1 
  And push the resultant string back to Stack
  Repeat the above steps until end of Prefix expression.
   */
  public static void main(String args[]) 
  { 
    String inExp = "(A-B/C)*(A/K-L)";
    //String inExp = "a+b*(c^d-e)^(f+g*h)-i"; 
    System.out.println("InfixToPostfix : " + infixToPostfix(inExp));
    System.out.println("InfixToPrefix : " + infixToPrefix(inExp));
  } 
}
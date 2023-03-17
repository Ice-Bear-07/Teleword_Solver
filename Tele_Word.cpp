#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
using namespace std;
#include <chrono> 
using namespace std::chrono;
void Setcolor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
bool inrows(char word[], char grid[][15], int grid2[][15], int wordl)
{
	bool find = false;
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			int w = 0;
			if (word[w] == grid[x][y])
			{
				bool match = true;
				int m = x, n = y, o = w, a = 0, ar[1000];;
				for (int j = 1; j <= wordl; j++)
				{
					if (match == true)
					{
						if (word[o] == grid[m][n])
						{
							ar[a] = m;  a++;  ar[a] = n;  a++; n++; o++;
							if (j == wordl)
							{
								
								find = true;
								for (int b = 0; b < a; b++)
								{
									int t[2];
									if (b % 2 == 0)
									{
										t[0] = ar[b];
									}
									else
									{
										t[1] = ar[b];
									}
									if (b % 2 == 1)
									{
										int x, y;
										x = t[0];
										y = t[1];
										grid2[x][y] = grid2[x][y] + 1;
									}


								}

							}

						}
						else
						{
							match = false;
						}
					}
				}
			}
		}
	}
	return find;

}
bool incol(char word[], char grid[][15], int grid2[][15], int wordl)
{
	bool find = false;
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			int w = 0;
			if (word[w] == grid[y][x])
			{
				bool match = true;
				int m = x, n = y, o = w, a = 0, ar[1000];;
				for (int j = 1; j <= wordl; j++)
				{
					if (match == true)
					{
						if (word[o] == grid[n][m])
						{
							ar[a] = n;  a++;  ar[a] = m;  a++; n++; o++;
							if (j == wordl)
							{
								find = true;
								for (int b = 0; b < a; b++)
								{
									int t[2];
									if (b % 2 == 0)
									{
										t[0] = ar[b];
									}
									else
									{
										t[1] = ar[b];
									}
									if (b % 2 == 1)
									{
										int x, y;
										x = t[0];
										y = t[1];
										grid2[x][y] = grid2[x][y] + 1;
									}
								}
							}

						}
						else
						{
							match = false;
						}
					}
				}
			}
		}
	}
	return find;
}
int main()
{
	ifstream teleworld("teleword_5.txt");

	if (teleworld.fail())
	{
		cout << "File not accessed";
		system("pause");
	}
	else
	{
		char a[500], grid[15][15], words[500];
		int x = 0, noc = 0, c = 0;;
		int wordlen;
		int grid2[15][15];
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				grid2[i][j] = 0;
			}
		}
		while (teleworld.getline(a, 500))
		{
			if (x < 15)
			{
				for (int y = 0, z = 0; y < 29; y += 2, z++)
				{
					grid[x][z] = a[y];
				}
			}

			else if (x == 16)
			{
				wordlen = strlen(a);
				for (int x = 0; x < wordlen; x++)
				{
					words[x] = a[x];
					if (a[x] == ',')
					{
						noc++;
					}
				}
			}
			x++;
		}
		for (int x = 0; x < 15; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
		for (int x = 0; x < wordlen; x++)
		{
			cout << words[x];
		}
		cout << endl;
		cout << endl;
		char choice;//to get input from user....
		cout << "Press S to solve the puzzle at once" << endl;
		cout << "Press T to solve the puzzle step by step. " << endl;
		cout << "Press X to print puzzle statistics." << endl;
		cin >> choice;
		if (choice == 'S')
		{
			// to get one word
			char word[15];
			int l = 0;
			while (noc >= 0)
			{
				bool istrue = true;
				int wordl = 0, i = 0;
				while (l < wordlen && istrue == true)
				{
					if (words[l] == ',')
					{
						istrue = false;
					}
					else if (words[l] == ' ' || words[l] == '.')
					{
					}
					else
					{
						word[i] = words[l];
						i++;
						wordl++;
					}
					l++;
				}

				for (int j = 0; j < wordl; j++)
				{
					if (j == 0)
					{
					}
					else
					{
						if (j == (wordl - 1))
						{
							word[j] = word[j] - 32;
						}
						else
						{
							word[j] = word[j] - 32;
						}
					}

				}
				
				// for finding a word in teleword
				bool find = false;
				// reverse word
				char temp[15];
				for (int i = 0, j = wordl - 1; i <= wordl; i++, j--)
				{
					temp[i] = word[j];
				}
				//in rows
				find = inrows(word, grid, grid2, wordl);
				if (find == false)
				{
					find = inrows(temp, grid, grid2, wordl);
				}
				//in columns
				if (find == false)
				{
					find = incol(word, grid, grid2, wordl);

				}
				if (find == false)
				{
					find = incol(temp, grid, grid2, wordl);
				}
				//in diagonal 1 
				if (find == false)
				{
					for (int i = 0; i < 15; i++)//lower
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (word[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}

				}

				if (find == false)//upper
				{
					for (int i = 1; i < 15; i++)
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (word[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}

				//in diagonal 2
				if (find == false)
				{
					for (int i = 0; i < 15; i++)
					{
						for (int l = i, k = 14; l < 15, k >= 0; l++, k--)
						{
							int w = 0;
							if (word[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n--; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}


						}
					}
				}

				if (find == false)
				{
					for (int i = 13; i >= 0; i--)
					{
						for (int l = i, k = 0; l >= 0 && k < 15; k++, l--)
						{
							int w = 0;
							if (word[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m--; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}
				//use of temp
				//in diagonal 1 
				if (find == false)
				{
					for (int i = 0; i < 15; i++)//lower
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (temp[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{
														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}

				}

				if (find == false)
				{
					for (int i = 1; i < 15; i++)
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (temp[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}

				//in diagonal 2
				if (find == false)
				{
					for (int i = 0; i < 15; i++)
					{
						for (int l = i, k = 14; l < 15, k >= 0; l++, k--)
						{
							int w = 0;
							if (temp[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n--; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}


						}
					}
				}

				if (find == false)
				{
					for (int i = 13; i >= 0; i--)
					{
						for (int l = i, k = 0; l >= 0 && k < 15; k++, l--)
						{
							int w = 0;
							if (temp[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m--; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}
				noc--;

			}//word finding bracket
			for (int i = 0; i < 15; i++)//for color output
			{
				for (int j = 0; j < 15; j++)
				{
					if (grid2[i][j] == 1)
					{
						Setcolor(69);
						cout << grid[i][j] << " ";
					}
					else if (grid2[i][j] == 2)
					{
						Setcolor(19);
						cout << grid[i][j] << " ";
					}
					else if (grid2[i][j] > 2)
					{
						Setcolor(49);
						cout << grid[i][j] << " ";
					}
					else
					{
						Setcolor(79);
						cout << grid[i][j] << " ";
					}
				}
				cout << endl;
			}
			Setcolor(7);
			cout << "TELEWORD:";
			for (int i = 0; i < 15; i++)//for color output
			{
				for (int j = 0; j < 15; j++)
				{
					if (grid2[i][j] == 0)
					{
						cout << grid[i][j];
					}
				}
			}
			cout << endl;
			//file handling bracket

			system("pause");
			return 0;
		}
		else if (choice == 'T')//for T
		{
			// to get one word
			char word[15];
			int l = 0;
			while (noc >= 0)
			{
				bool istrue = true;
				int wordl = 0, i = 0;
				while (l < wordlen && istrue == true)
				{
					if (words[l] == ',')
					{
						istrue = false;
					}
					else if (words[l] == ' ' || words[l] == '.')
					{
					}
					else
					{
						word[i] = words[l];
						i++;
						wordl++;
					}
					l++;
				}

				for (int j = 0; j < wordl; j++)
				{
					if (j == 0)
					{
						cout << word[j];
					}
					else
					{
						if (j == (wordl - 1))
						{
							cout << word[j] << " ";
							word[j] = word[j] - 32;
						}
						else
						{
							cout << word[j];
							word[j] = word[j] - 32;
						}
					}

				}
				// for finding a word in teleword
				bool find = false;
				// reverse word
				char temp[15];
				for (int i = 0, j = wordl - 1; i <= wordl; i++, j--)
				{
					temp[i] = word[j];
				}
				//in rows
				find = inrows(word, grid, grid2, wordl);
				if (find == false)
				{
					find = inrows(temp, grid, grid2, wordl);
				}
				//in columns
				if (find == false)
				{
					find = incol(word, grid, grid2, wordl);

				}
				if (find == false)
				{
					find = incol(temp, grid, grid2, wordl);
				}

				//in diagonal 1 
				if (find == false)
				{
					for (int i = 0; i < 15; i++)//lower
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (word[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}

				}

				if (find == false)
				{
					for (int i = 1; i < 15; i++)
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (word[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}

				//in diagonal 2
				if (find == false)
				{
					for (int i = 0; i < 15; i++)
					{
						for (int l = i, k = 14; l < 15, k >= 0; l++, k--)
						{
							int w = 0;
							if (word[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n--; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}


						}
					}
				}

				if (find == false)
				{
					for (int i = 13; i >= 0; i--)
					{
						for (int l = i, k = 0; l >= 0 && k < 15; k++, l--)
						{
							int w = 0;
							if (word[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m--; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}
				//use of temp
				//in diagonal 1 
				if (find == false)
				{
					for (int i = 0; i < 15; i++)//lower
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (temp[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}

				}

				if (find == false)
				{
					for (int i = 1; i < 15; i++)
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (temp[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}

				//in diagonal 2
				if (find == false)
				{
					for (int i = 0; i < 15; i++)
					{
						for (int l = i, k = 14; l < 15, k >= 0; l++, k--)
						{
							int w = 0;
							if (temp[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n--; m++; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else

										{
											match = false;
										}
									}
								}
							}


						}
					}
				}

				if (find == false)
				{
					for (int i = 13; i >= 0; i--)
					{
						for (int l = i, k = 0; l >= 0 && k < 15; k++, l--)
						{
							int w = 0;
							if (temp[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m--; o++;
											if (j == wordl)
											{
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}
				cout << endl;
				for (int i = 0; i < 15; i++)//for color output
				{
					for (int j = 0; j < 15; j++)
					{
						if (grid2[i][j] == 1)
						{
							Setcolor(6);
							cout << grid[i][j] << " ";
						}
						else if (grid2[i][j] == 2)
						{
							Setcolor(1);
							cout << grid[i][j] << " ";
						}
						else if (grid2[i][j] > 2)
						{
							Setcolor(4);
							cout << grid[i][j] << " ";
						}
						else
						{
							Setcolor(7);
							cout << grid[i][j] << " ";
						}
					}
					cout << endl;
				}
				Setcolor(7);
				if (noc == 0)
				{
					cout << "TELEWORD:";
					for (int i = 0; i < 15; i++)//for color output
					{
						for (int j = 0; j < 15; j++)
						{
							if (grid2[i][j] == 0)
							{
								cout << grid[i][j];
							}
						}
					}
					cout << endl;
				}
				system("pause");
				system("cls");

				cout << endl;
				noc--;

			}//word finding bracket


		}

		else if (choice == 'X')//for X
		{
			auto start = chrono::steady_clock::now();
			// to get one word
			char word[15];
			int l = 0, total = noc + 1, wlen = 0, avg, longw = 0, shortw = 100, d1 = 0, d2 = 0, ho = 0, vi = 0, hf = 0, hr = 0, vf = 0, vr = 0, diag = 0, sca = 0;;
			while (noc >= 0)
			{
				
				bool istrue = true;
				int wordl = 0, i = 0;
				while (l < wordlen && istrue == true)
				{
					if (words[l] == ',')
					{
						istrue = false;
					}
					else if (words[l] == ' ' || words[l] == '.')
					{
					}
					else
					{
						word[i] = words[l];
						i++;
						wordl++;
					}
					l++;
				}

				for (int j = 0; j < wordl; j++)
				{
					if (j == 0)
					{
					}
					else
					{
						if (j == (wordl - 1))
						{
							word[j] = word[j] - 32;
						}
						else
						{
							word[j] = word[j] - 32;
						}
					}

				}
				int le = wordl;
				// for finding a word in teleword
				bool find = false;
				// reverse word
				char temp[15];
				for (int i = 0, j = wordl - 1; i <= wordl; i++, j--)
				{
					temp[i] = word[j];
				}
				//in rows
				
				find = inrows(word, grid, grid2, wordl);
				if (find == true)
				{
					hf++;
					ho++;
				}
				if (find == false)
				{
					find = inrows(temp, grid, grid2, wordl);
					if (find == true)
					{
						hr++;
						ho++;
					}
				}
				//in columns
				if (find == false)
				{
					find = incol(word, grid, grid2, wordl);
					if (find == true)
					{
						vf++;
						vi++;
					}
				}
				if (find == false)
				{
					find = incol(temp, grid, grid2, wordl);
					if (find == true)
					{
						vr++;
						vi++;
					}
				}
				//in diagonal 1 
				
				if (find == false)
				{
					for (int i = 0; i < 15; i++)//lower
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (word[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n++; m++; o++;
											if (j == wordl)
											{
												diag++;
												d1++;
												find = true;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}

				}

				if (find == false)//upper
				{
					for (int i = 1; i < 15; i++)
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (word[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d1++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}

				//in diagonal 2
				if (find == false)
				{
					for (int i = 0; i < 15; i++)
					{
						for (int l = i, k = 14; l < 15, k >= 0; l++, k--)
						{
							int w = 0;
							if (word[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n--; m++; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d1++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}


						}
					}
				}

				if (find == false)
				{
					for (int i = 13; i >= 0; i--)
					{
						for (int l = i, k = 0; l >= 0 && k < 15; k++, l--)
						{
							int w = 0;
							if (word[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (word[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m--; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d1++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}
				//use of temp
				//in diagonal 1 
				if (find == false)
				{
					for (int i = 0; i < 15; i++)//lower
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (temp[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d2++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{
														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}

				}

				if (find == false)
				{
					for (int i = 1; i < 15; i++)
					{
						for (int l = i, k = 0; l < 15 && k < 15; l++, k++)
						{
							int w = 0;
							if (temp[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m++; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d2++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}

				//in diagonal 2
				if (find == false)
				{
					for (int i = 0; i < 15; i++)
					{
						for (int l = i, k = 14; l < 15, k >= 0; l++, k--)
						{
							int w = 0;
							if (temp[w] == grid[l][k])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[m][n])
										{
											ar[a] = m;  a++;  ar[a] = n;  a++; n--; m++; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d2++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}


						}
					}
				}

				if (find == false)
				{
					for (int i = 13; i >= 0; i--)
					{
						for (int l = i, k = 0; l >= 0 && k < 15; k++, l--)
						{
							int w = 0;
							if (temp[w] == grid[k][l])
							{
								bool match = true;
								int m = l, n = k, o = w, a = 0, ar[1000];;
								for (int j = 1; j <= wordl; j++)
								{
									if (match == true)
									{
										if (temp[o] == grid[n][m])
										{
											ar[a] = n;  a++;  ar[a] = m;  a++; n++; m--; o++;
											if (j == wordl)
											{
												find = true;
												diag++;
												d2++;
												for (int b = 0; b < a; b++)
												{
													int t[2];
													if (b % 2 == 0)
													{

														t[0] = ar[b];
													}
													else
													{

														t[1] = ar[b];
													}
													if (b % 2 == 1)
													{
														int x, y;
														x = t[0];
														y = t[1];
														grid2[x][y] = grid2[x][y] + 1;
													}
												}
											}

										}
										else
										{
											match = false;
										}
									}
								}
							}

						}
					}
				}
				//to calculate stats
				
				wlen = wlen + wordl;
				if (noc == 0)
				{
					avg = wlen / total;
				}
				noc--;
				if (wordl > longw)
				{
					longw = wordl;
				}
				else if (wordl < shortw)
				{
					shortw = wordl;
				}

			}//word finding bracket
			for (int i = 0; i < 15; i++)//for color output
			{
				for (int j = 0; j < 15; j++)
				{
					if (grid2[i][j] == 1)
					{
						Setcolor(6);
						cout << grid[i][j] << " ";
					}
					else if (grid2[i][j] == 2)
					{
						Setcolor(1);
						cout << grid[i][j] << " ";
					}
					else if (grid2[i][j] > 2)
					{
						Setcolor(4);
						cout << grid[i][j] << " ";
					}
					else
					{
						Setcolor(7);
						cout << grid[i][j] << " ";
					}
				}
				cout << endl;
				
			}
			Setcolor(7);
			cout << "TELEWORD:";
			for (int i = 0; i < 15; i++)//for color output
			{
				for (int j = 0; j < 15; j++)
				{
					if (grid2[i][j] == 0)
					{
						cout << grid[i][j];
					}
				}
			}
			
			cout << endl;
			// to calculate time
			auto stop = chrono::steady_clock::now();
			auto diff = stop - start;
			cout << "Time to Solve: " << chrono::duration <double, milli>(diff).count() << " milliseconds" << endl;
			// to calculate word stats
			cout << "Longest Word Length: " << longw << endl;
			cout << "Shortest Word Length: " << shortw << endl;
			cout << "Average Length: " << avg<<endl;
			// word distribution
			cout << "Horizontal:" << ho << "(" << hf << "," << hr << "),"
				<< "Virtical:" << vi << "(" << vf << "," << vr << "),"
				<< "Diagonal:" << diag << "(" << d1 << "," << d2 << ")."<<endl;
			//teleword scatter
			for (int i = 0; i < 15; i++)
			{
				bool scatter = true;
				for (int j = 0; j < 15; j++ && scatter)
				{
					if (grid2[i][j] == 0)
					{
						scatter= false;
					}
				}
				if (scatter == false)
				{
					sca++;
				}
			}
			cout << "Teleword Scatter: " << sca << endl;
			//file handling bracket

			system("pause");
			return 0;
		}
		system("pause");
		return 0;
	}

}

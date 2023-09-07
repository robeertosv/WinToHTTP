#include <Windows.h> //Incluir la API de Windows
#include "resource.h" //Incluir los recursos de la APP (La ventana, botones, campo de texto...)

#include <string>
#include <cstring>

INT_PTR CALLBACK fVentana(HWND, UINT, WPARAM, LPARAM); //Funci�n que se usar� para detectar las acciones del usuario en la App

//Funci�n principal, como es una APP nativa no se usa int main sino int WinMain, que toma de par�metros la instancia en la que se ejecuta, la instancia de la que proviene, la l�nea de comandos y un int que servir� para indicar como renderizar la ventana princiapal
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmdLine, int cShow) {
	HWND hVentana = CreateDialog(hInst, MAKEINTRESOURCE(VENTANA_PRINCIPAL), NULL, fVentana); //Creamos la ventana principal, indicando donde (la instancia), con que recurso (la ventana dise�ada), la ventana padre (NULL porque es la principal) y una funci�n CALLBACK (fVentana)

	MSG msg; //Mensajes que llegan por parte del SO
	ZeroMemory(&msg, sizeof(MSG)); //Borrar la memoria que pueda haber en la direccion del msg

	ShowWindow(hVentana, cShow); //Mostrar la ventana que se ha creado al principio en el modo preferido por el SO, se pueden forzar otras apariencias

	while (GetMessage(&msg, NULL, NULL, NULL)) { //Bucle que ser� TRUE mientras la App est� en ejecuci�n (NULL porque no usa ning�n filtro)
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

INT_PTR CALLBACK fVentana(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
		case WM_CLOSE: //Destruir la ventana al pulsar el bot�n de cerrar
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(200); //Destruir el proceso (el numero puede ser cualquiera, 200 porque es OK en HTTP)
			break;

		case WM_COMMAND: //Eventos personalizados
			//Cuando se pulse el bot�n
			if (LOWORD(wparam) == SEND_BTN && HIWORD(wparam) == BN_CLICKED) {
				HWND text = GetDlgItem(hwnd, TEXT_NAME); //Guardar el TEXT INPUT de la ventana
				int textLen = GetWindowTextLength(text); //Guardar longitud del texto

				if (textLen >= 1) {
					char name[50]; //Variable en la que se guardar� el nombre (m�ximo 50 caracteres)
					GetWindowText(text, name, textLen+1); //Coger el texto y guardarlo

					std::string n(name);
					std::string query = "curl -X POST -H \"Content-Type: application/json\" --data \"{\\\"name\\\": \\\"" + n + "\\\"}\" http://localhost:3000/api"; //Petici�n cURL con el m�todo POST, que especifica que va a enviar un JSON, con el JSON que incluye el nombre a la direcci�n localhost:3000/api

					system(query.c_str()); //Ejecutar el comando desde cmd
				}
				else {
					MessageBox(NULL, "Introduce tu nombre", "ERROR", MB_OK); //Mostrar mensaje de error si no se pone ning�n nombre
				}
			}
			break;
	}
	return FALSE;
}
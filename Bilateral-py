{
 "cells": [
  {
   "cell_type": "markdown",
   "id": "b20a776c",
   "metadata": {},
   "source": [
    "# Filtro Pasa Bajos de Segundo Orden - Bilateral"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "6c11aa8f",
   "metadata": {},
   "outputs": [
    {
     "ename": "SyntaxError",
     "evalue": "invalid syntax (Temp/ipykernel_8016/2360134605.py, line 51)",
     "output_type": "error",
     "traceback": [
      "\u001b[1;36m  File \u001b[1;32m\"C:\\Users\\Carlo\\AppData\\Local\\Temp/ipykernel_8016/2360134605.py\"\u001b[1;36m, line \u001b[1;32m51\u001b[0m\n\u001b[1;33m    return line, and line2,\u001b[0m\n\u001b[1;37m                 ^\u001b[0m\n\u001b[1;31mSyntaxError\u001b[0m\u001b[1;31m:\u001b[0m invalid syntax\n"
     ]
    }
   ],
   "source": [
    "#Librerias\n",
    "%matplotlib notebook\n",
    "import serial\n",
    "import time\n",
    "import numpy as np\n",
    "import matplotlib.pyplot as plt\n",
    "from matplotlib.animation import FuncAnimation #Tiempo real\n",
    "plt.style.use('fivethirtyeight') #Estilo\n",
    "\n",
    "#Comunicación Serial\n",
    "arduino = serial.Serial('COM3',9600,timeout = 2);\n",
    "time.sleep = 1;\n",
    "t = 0; #Señal Ruidosa\n",
    "d_señal = []; #Graficar\n",
    "d_señalgraf = [];\n",
    "d_filtro = [];\n",
    "tiempo = [];\n",
    "while (t <= 1):\n",
    "    señal = np.sin(2*np.pi*5*t) + np.sin(2*np.pi*50*t); #Señal de Prueba\n",
    "    t = t + 0.001; #Muestras - 1000\n",
    "    d_señal.append(str(señal)); \n",
    "    d_señalgraf.append(señal);\n",
    "    tiempo.append(t);\n",
    "\n",
    "for i in d_señal: \n",
    "    arduino.write((i + '\\n').encode()); \n",
    "    salida = arduino.readline().decode('ascii'); \n",
    "    d_filtro.append(salida);\n",
    "   \n",
    "d_filtro[0] = \"0.00\\r\\n\"; #Valor que no cambia. sin0 = 0 \n",
    "cuenta = 0;\n",
    "\n",
    "for k in d_filtro:\n",
    "    strorg = d_filtro[cuenta];\n",
    "    strnew = strorg.replace('\\r\\n','');\n",
    "    d_filtro[cuenta] = float(strnew);\n",
    "    cuenta = cuenta + 1;\n",
    "    \n",
    "arduino.close(); \n",
    "\n",
    "#Graficacion en tiempo real\n",
    "fig = plt.figure()\n",
    "ax = plt.axes(xlim=(0, 1), ylim=(-2.5,2.5))\n",
    "line, = ax.plot([], [], lw=2)\n",
    "line2, = ax.plot([], [], lw=2)\n",
    "\n",
    "# animation function.  This is called sequentially\n",
    "def animate(l):\n",
    "    line.set_data(tiempo[:l], d_filtro[:l])\n",
    "    line2.set_data(tiempo[:l], d_señal[:l])\n",
    "    return line, line2,\n",
    "\n",
    "anim = FuncAnimation(fig, animate, interval=1)\n",
    "plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "ab935839",
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "1269a301",
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.7"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}

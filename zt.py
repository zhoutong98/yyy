import numpy as np
import pyqtgraph as pg

app = pg.mkQApp()
x = np.linspace(0, 6*np.pi, 100)
y = np.sin(x)
p = pg.plot(x, y, title=u'最简单绘图例子', left='Amplitude / V', buttom='t / s')
p.setLabels(title='y = sin(x)')
app.exec()

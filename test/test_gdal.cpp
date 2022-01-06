#include <QtTest/QTest>
#include <cmath>
#include <gdal_tools.h>

class TestGDAL : public QObject {
    Q_OBJECT
private slots:
    void testGDAL() {
        CoordinateConvert convert(23.0, 113.0);
        convert.setSourceSrs("4326", CoordinateConvert::EPSG);
        convert.setTargetSrs("+proj=tmerc +lat_0=0 +lon_0=114 +k=1 +x_0=500000 +y_0=0 +ellps=GRS80 +units=m +no_defs ", CoordinateConvert::Proj4);
        convert.transform();
        QVERIFY(fabs(convert.targetX - 397473.82) < 1e-2);
        QVERIFY(fabs(convert.targetY - 2544887.19) < 1e-2);
    }
};

QTEST_MAIN(TestGDAL)

#include "test_gdal.moc"
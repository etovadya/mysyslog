//Сделать тестовое приложение демон mysyslog-daemon, который автоматически запускается во время старта компьютера и постоянно выводит в лог данные с разным уровнем. 
//Приложение настраивается при помощи конфигурационного файла /etc/mysyslog/mysyslog.cfg. В конфигурационном файле задается: путь, формат и драйвер. 
//Демон должен корректно обрабатывать получаемые сигналы и должен запускаться и останавливаться через systemctl.

var dest = './';
var src = './source';

module.exports = {
	//Конфигурация для Sass
	sass: {
		//Папка с исходныи файлами и маска выборки файлов
		src: src + '/sass/**/*.scss',
		//Папка назначения
		dest: dest + '/css',
		settings: {
			//Сжимаем файл
			outputStyle: 'compressed',
			//Выводим логив  консоль
			errLogToConsole: true
		},
		//Папка в которой будут создаваться map файлы
		map: dest + '/map'
	},

	//Конфигурация для autoprefixer
	prefix: {
		overrideBrowserslist: ['> 1%', 'last 2 versions', 'Firefox ESR', 'iOS 7'],
		cascade: false,
	},
	//Конфигурация для javascript
	js: {
		//Папка с исходныи файлами и маска выборки файлов
		src: src + '/js/*.js',
		//Папка назначения
		dest: dest + 'js'
	},
	//Конфигурация для html
	html: {
		//Папка с исходныи файлами и маска выборки файлов
		src: src + '/index.html',
		//Папка назначения
		dest: dest + ''
	},
	//Конфигурация для html
	uncss: {
		//Папка с исходныи файлами и маска выборки файлов
		html: src + '/index.html',
	},
	//Конфигурация минификации JavaScript
	uglify: {
		settings: {
			compress: {
				booleans: true,
				conditionals: true,
				dead_code: true,
				drop_console: true,
				if_return: true,
				join_vars: true,
				sequences: true,
				unused: true
			}
		}
	},
};
var gulp = require('gulp');
var sass = require('gulp-sass');
var sourcemaps = require('gulp-sourcemaps');
var post = require('gulp-postcss');
var prefixer = require('autoprefixer');
var flexboxBug = require('postcss-flexbugs-fixes');
var postFontSize = require('postcss-short-font-size');
var postUncss = require('postcss-uncss');
var handleErrors = require('../util/handleErrors');

var config = require('../config').sass;
var configPrefix = require('../config').prefix;
var configUncss = require('../config').uncss;

var dependents = require('gulp-dependents');

var processors = [
	prefixer(configPrefix),
	flexboxBug,
	postFontSize,
	postUncss(configUncss),
];

function sassFunc() {

	return gulp.src(config.src, { since: gulp.lastRun(sassFunc) })
		.pipe(dependents())
		.pipe(sourcemaps.init())
		.pipe(sass(config.settings))
		.on('error', handleErrors)
		.pipe(post(processors))
		.pipe(sourcemaps.write(config.map))
		.pipe(gulp.dest(config.dest))
}

//Обязательно экспортируем
exports.sassTask = sassFunc;